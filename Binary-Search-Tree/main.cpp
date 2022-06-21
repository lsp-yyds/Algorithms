#include "FileOps.h"
#include "SequenceST.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

template <typename Key, typename Value>
class BST {
  private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node( Key key, Value value ) {
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };

    Node *root;
    int count;

  public:
    BST() {
        root = NULL;
        count = 0;
    }

    ~BST() { destroy( root ); }

    int size() { return count; }

    bool isEmpty() {
        return count == 0;
        // return root == NULL;
    }

    void insert( Key key, Value value ) { root = insert( root, key, value ); }

    bool contain( Key key ) { return contain( root, key ); }

    Value *search( Key key ) { return search( root, key ); }

    // 前序遍历
    void preOrder() { preOrder( root ); }

    // 中序遍历
    void inOrder() { inOrder( root ); }

    // 后序遍历
    void postOrder() { postOrder( root ); }

    // 层序遍历
    void levelOrder() {
        queue<Node *> q;
        q.push( root );
        while ( !q.empty() ) {
            Node *node = q.front();
            q.pop();

            cout << node->key << endl;

            if ( node->left != NULL ) q.push( node->left );
            if ( node->right != NULL ) q.push( node->right );
        }
    }

    // 寻找最小的键值
    Key minimum() {
        assert( count != 0 );
        Node *minNode = minimum( root );
        return minNode->key;
    }

    // 寻找最大的键值
    Key maximum() {
        assert( count != 0 );
        Node *maxNode = maximum( root );
        return maxNode->key;
    }

    // 从二叉树删除最小值所在节点
    void removeMin() {
        if ( root ) root = removeMin( root );
    }

    // 从二叉树删除最大值所在节点
    void removeMax() {
        if ( root ) root = removeMax( root );
    }

  private:
    Node *insert( Node *node, Key key, Value value ) {

        if ( node == NULL ) {
            count++;
            return new Node( key, value );
        }
        if ( key == node->key )
            node->value = value;
        else if ( key < node->key )
            node->left = insert( node->left, key, value );
        else // (key > node->key)
            node->right = insert( node->right, key, value );

        return node;
    }

    // 查看以node为根的二叉搜索树中是否包含键值为key的节点
    bool contain( Node *node, Key key ) {
        if ( node == NULL ) return false;

        if ( key == node->key )
            return true;
        else if ( key < node->key )
            return contain( node->left, key );
        else //(key > node->key)
            return contain( node->right, key );
    }

    // 在以node为根的二叉搜索树中查找key所对应的value
    Value *search( Node *node, Key key ) {
        if ( node == NULL ) return NULL;
        if ( key == node->key )
            return &( node->value );
        else if ( key < node->key )
            return search( node->left, key );
        else // ( key > node->key )
            return search( node->right, key );
    }

    // 对以node为根的二叉搜索树进行前序遍历
    void preOrder( Node *node ) {

        if ( node != NULL ) {
            cout << node->key << endl;
            preOrder( node->left );
            preOrder( node->right );
        }
    }

    // 对以node为根的二叉搜索树进行中序遍历
    void inOrder( Node *node ) {
        if ( node != NULL ) {
            inOrder( node->left );
            cout << node->key << endl;
            inOrder( node->right );
        }
    }

    // 对以node为根的二叉搜索树进行后序遍历
    void postOrder( Node *node ) {
        if ( node != NULL ) {
            postOrder( node->left );
            postOrder( node->right );
            cout << node->key << endl;
        }
    }

    void destroy( Node *node ) {

        if ( node != NULL ) {
            destroy( node->left );
            destroy( node->right );

            delete node;
            count--;
        }
    }

    Node *minimum( Node *node ) {
        if ( node->left == NULL ) return node;

        return minimum( node->left );
    }

    Node *maximun( Node *node ) {
        if ( node->right == NULL ) return node;

        return maximum( node->right );
    }

    Node *removeMin( Node *node ) {

        if ( node->left == NULL ) {
            Node *rightNode = node->right;
            delete node;
            count--;
            return rightNode;
        }

        node->left = removeMin( node->left );
        return node;
    }

    Node *removeMax( Node *node ) {

        if ( node->right == NULL ) {
            Node *leftNode = node->left;
            delete node;
            count--;
            return leftNode;
        }

        node->right = removeMax( node->right );
        return node;
    }
};

// 测试二分搜索树和顺序查找表之间的性能差距
// 二分搜索树的性能远远优于顺序查找表
int main() {

    // 使用圣经作为我们的测试用例
    string filename = "bible.txt";
    vector<string> words;
    if ( FileOps::readFile( filename, words ) ) {

        cout << "There are totally " << words.size() << " words in " << filename
             << endl;
        cout << endl;

        // 测试 BST
        time_t startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        BST<string, int> bst = BST<string, int>();
        for ( vector<string>::iterator iter = words.begin();
              iter != words.end(); iter++ ) {
            int *res = bst.search( *iter );
            if ( res == NULL )
                bst.insert( *iter, 1 );
            else
                ( *res )++;
        }

        // 输出圣经中god一词出现的频率
        if ( bst.contain( "god" ) )
            cout << "'god' : " << *bst.search( "god" ) << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        time_t endTime = clock();

        cout << "BST , time: " << double( endTime - startTime ) / CLOCKS_PER_SEC
             << " s." << endl;
        cout << endl;

        // 测试顺序查找表 SST
        startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        SequenceST<string, int> sst = SequenceST<string, int>();
        for ( vector<string>::iterator iter = words.begin();
              iter != words.end(); iter++ ) {
            int *res = sst.search( *iter );
            if ( res == NULL )
                sst.insert( *iter, 1 );
            else
                ( *res )++;
        }

        // 输出圣经中god一词出现的频率
        if ( sst.contain( "god" ) )
            cout << "'god' : " << *sst.search( "god" ) << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        endTime = clock();

        cout << "SST , time: " << double( endTime - startTime ) / CLOCKS_PER_SEC
             << " s." << endl;
    }

    return 0;
}