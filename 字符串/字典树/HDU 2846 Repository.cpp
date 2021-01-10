/*
字典树 - 叶子 结点打标记

拿后面给出的字符串建立字典树

1 MLE 建立字典树想法错误， 应该用后面给出的字符串建立字典树
*/

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int NODECACHES = 500010;               // 修改点 1
const int TREENODE = 26;                     // 修改点 2
const int TREEHASH_BASE = 'a';               // 修改点 3
const int TRIEDATA_INIT = -1;                // 修改点 4

typedef char ValueType;
typedef int TrieData;

// 字典树结点类
class TrieNode {
private:
    TrieData td_;
    TrieNode *nodes_[TREENODE];

public:
    inline void setSon(int sonIdx, TrieNode *pkSon) {
        nodes_[sonIdx] = pkSon;
    }

    inline TrieNode *getSon(int sonIdx) {
        return nodes_[sonIdx];
    }

    inline void addValue(int add) {
        if (td_ == TRIEDATA_INIT) td_ = add;
    }

    inline TrieData getValue() {
        return td_;
    }

    inline void reset() {
        td_ = TRIEDATA_INIT;
        memset(nodes_, NULL, sizeof(nodes_));
    }
};

// 字典树类
class TrieTree {
public:
    TrieTree(int nodeCacheCount);
    virtual ~TrieTree();

    void initialize();
    virtual int insert(int vSize, ValueType v[], int w);
    virtual void query(int vSize, ValueType v[]);

private:
    TrieNode *genNode();
    int getSonIndex(ValueType v);

private:
    int nodeId_;
    TrieNode *nodes_;
    TrieNode *root_;
};

TrieTree::TrieTree(int nodeCacheCount) : nodes_(NULL), root_(NULL), nodeId_(0) {
    nodes_ = new TrieNode[nodeCacheCount];
}

TrieTree::~TrieTree() {
    if (nodes_) {
        delete[] nodes_;
    }
}

void TrieTree::initialize() {
    nodeId_ = 0;
    root_ = genNode();
}

TrieNode *TrieTree::genNode() {
    TrieNode *pkNode = &(nodes_[nodeId_++]);
    pkNode->reset();
    return pkNode;
}

int TrieTree::getSonIndex(ValueType v) {
    return v - TREEHASH_BASE;
}

int TrieTree::insert(int vSize, ValueType v[], int w) {
    TrieNode *pkNow = root_;
    for (int i = 0; i < vSize; ++i) {
        int sonIdx = getSonIndex(v[i]);
        if (!pkNow->getSon(sonIdx)) {
            pkNow->setSon(sonIdx, genNode());
        }
        pkNow = pkNow->getSon(sonIdx);
    }
    pkNow->addValue(w);
    return pkNow->getValue();
}

int ansCnt[100010], ansHash[100010], hashCase;

void TrieTree::query(int vSize, ValueType v[]) {
    TrieNode *pkNow = root_;
    for (int i = 0; i < vSize; ++i) {
        int sonIdx = getSonIndex(v[i]);
        if (!pkNow->getSon(sonIdx)) {
            return;
        }
        pkNow = pkNow->getSon(sonIdx);
        if (pkNow->getValue() != TRIEDATA_INIT) {
            if (ansHash[pkNow->getValue()] < hashCase) {
                ++ansCnt[pkNow->getValue()];
                ansHash[pkNow->getValue()] = hashCase;
            }

        }
    }
}

char merchandises[10010][22];
int ansIdx[100010];

int main() {
    int n, m;
    TrieTree tt(NODECACHES);
    hashCase = 1;

    while (scanf("%d", &n) != EOF) {

        tt.initialize();

        for (int i = 0; i < n; ++i) {
            scanf("%s", merchandises[i]);
        }

        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            char ch[25];
            scanf("%s", ch);
            int len = strlen(ch);
            ansCnt[i] = 0;
            ansIdx[i] = tt.insert(len, ch, i);
        }

        for (int i = 0; i < n; ++i) {
            int len = strlen(merchandises[i]);
            ++hashCase;
            for (int j = 0; j < len; ++j) {
                tt.query(len - j, merchandises[i] + j);
            }
        }

        for (int i = 0; i < m; ++i) {
            printf("%d\n", ansCnt[ansIdx[i]]);
        }

    }

    return 0;
}

/*
20
ad
ae
af
ag
ah
ai
aj
ak
al
ads
add
ade
adf
adg
adh
adi
adj
adk
adl
aes
10
b
a
d
ad
s
b
a
d
ad
s
*/