#include <iostream>
#include <queue>

using namespace std;

struct
 
Node {

  
char character;
  int frequency;
  Node* left;
  Node* right;

  Node(char character, int frequency) {
    this->character = character;
    this->frequency = frequency;
    this->left = NULL;
    this->right = NULL;
  }
};

struct Comparator {
  bool operator()(const Node* p1, const Node* p2) {
    return p1->frequency > p2->frequency;
  }
};

void buildHuffmanTree(string S, int f[], Node** root) {
  priority_queue<Node*, vector<Node*>, Comparator> minHeap;

  for (int i = 0; i < S.length(); i++) {
    Node* node = new Node(S[i], f[i]);
    minHeap.push(node);
  }

  while (minHeap.size() > 1) {
    Node* left = minHeap.top();
    minHeap.pop();

    Node* right = minHeap.top();
    minHeap.pop();

    Node* parent = new Node('\0', left->frequency + right->frequency);
    parent->left = left;
    parent->right = right;

    minHeap.push(parent);
  }

  *root = minHeap.top();
}

void printHuffmanCodes(Node* root, string code) {
  if (root->left == NULL && root->right == NULL) {
    cout << root->character << " : " << code << endl;
    return;
  }

  printHuffmanCodes(root->left, code + "0");
  printHuffmanCodes(root->right, code + "1");
}

int main() {
  string S = "abcdef";
  int f[] = {5, 9, 12, 13, 16, 45};

  Node* root = NULL;
  buildHuffmanTree(S, f, &root);

  printHuffmanCodes(root, "");

  return 0;
}