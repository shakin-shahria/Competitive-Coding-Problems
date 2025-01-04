#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
    char character;
    int frequency;
    Node *left, *right;
};


struct Compare {
    bool operator()(Node *a, Node *b) {
        return a->frequency > b->frequency; 
    }
};

//Createing nodes
Node *createNode(char character, int frequency, Node *left = nullptr, Node *right = nullptr) {
    Node *node = new Node();
    node->character = character;
    node->frequency = frequency;
    node->left = left;
    node->right = right;
    return node;
}

//generate HuffmanCodes
void generateCodes(Node *root, string code, char codes[256][256]) {
    if (!root)
        return;

    if (!root->left && !root->right) { // Leaf node
        strcpy(codes[root->character], code.c_str());
    }

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

// HuffmanCodes
void huffmanCoding(const char *input) {
    int freq[256] = {0};

  
    for (int i = 0; input[i] != '\0'; i++) {
        freq[input[i]]++;
    }

    
    priority_queue<Node *, vector<Node *>, Compare> pq;

    
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            pq.push(createNode((char)i, freq[i]));
    }
    }

    //Huffman tree
    while (pq.size() > 1) {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *combined = createNode('\0', left->frequency + right->frequency, left, right);
        pq.push(combined);
    }

    Node *root = pq.top();

   
    char codes[256][256] = {{0}};
    generateCodes(root, "", codes);

    cout << "Character\tFrequency\tCodeword\n";
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << (char)i << "\t\t" << freq[i] << "\t\t" << codes[i] << endl;
    }
 }
}



int main() {
    const char *input = "ABRACADARBACDADRDARC";
    huffmanCoding(input);
    return 0;
}
