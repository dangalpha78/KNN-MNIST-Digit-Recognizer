#include "main.hpp"
// #include "Dataset.hpp"
#include "kDTree.hpp"

void tc1()
{
    kDTree tree(2);
    tree.insert({5, 6});
    tree.insert({2, 2});
    tree.insert({7, 3});
    tree.insert({2, 8});
    tree.insert({8, 7});
    tree.insert({8, 1});
    tree.insert({9, 4});
    tree.insert({3, 5});
    tree.preorderTraversal();
}

void tc2()
{
    kDTree tree(2);
    tree.insert({5, 6});
    tree.insert({2, 2});
    tree.insert({7, 3});
    tree.insert({2, 8});
    tree.insert({8, 7});
    tree.insert({8, 1});
    tree.insert({9, 4});
    tree.insert({3, 5});
    tree.insert({9, 2});
    tree.preorderTraversal();
}

void tc3()
{
    kDTree tree(2);
    vector<vector<int>> pointList = {{5, 6}, {2, 2}, {7, 3}, {2, 8}, {8, 7}, {8, 1}, {9, 4}, {3, 5}};
    tree.buildTree(pointList);
    tree.preorderTraversal();
}

void tc4()
{
    kDTree tree(2);
    vector<vector<int>> pointList = {{5, 6}, {2, 2}, {7, 3}, {2, 8}, {8, 7}, {8, 1}, {9, 4}, {3, 5}};
    tree.buildTree(pointList);
    cout << tree.search({2, 2}) << endl;
    cout << tree.search({9, 3}) << endl;
}

void tc5()
{
    kDTree tree(2);
    tree.insert({5, 6});
    tree.insert({2, 2});
    tree.insert({7, 3});
    tree.insert({2, 8});
    tree.insert({8, 1});
    tree.insert({3, 5});
    tree.insert({9, 2});
    tree.remove({5, 6});
    tree.preorderTraversal();
}

void tc6()
{
    kDTree tree(2);
    tree.insert({5, 6});
    tree.insert({2, 2});
    tree.insert({7, 3});
    tree.insert({2, 8});
    tree.insert({3, 5});
    tree.insert({8, 2});
    tree.insert({8, 7});
    tree.insert({9, 2});
    tree.insert({9, 5});
    kDTreeNode *best = nullptr;
    tree.nearestNeighbour({9, 3}, best);
    cout << "Nearest neighbour of (9, 3) is " << *best << endl;
    cout << best->data[0] << ' ' << best->data[1] << endl;
}

void tc7()
{
    kDTree tree(2);
    tree.insert({5, 6});
    tree.insert({2, 2});
    tree.insert({7, 3});
    tree.insert({2, 8});
    tree.insert({3, 5});
    tree.insert({8, 2});
    tree.insert({8, 7});
    tree.insert({9, 2});
    tree.insert({9, 5});
    vector<kDTreeNode *> bestList;
    tree.kNearestNeighbour({9, 3}, 5, bestList);
    cout << "5 Nearest neighbour of (9, 3) are: ";
    for (auto node : bestList)
    {
        cout << *node << " ";
    }
}

void tc8()
{
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    int nRows, nCols;

    kNN knn;
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, -1, 1, -1);
    Dataset label = dataset.extract(0, -1, 0, 0);

    train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);

    std::cout << "y_pred" << endl;
    y_pred.printHead(10, 10);
    std::cout << endl;
    std::cout << "y_test" << endl;
    y_test.printHead(10, 10);
    std::cout << endl;
}

void tc9()
{
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    int nRows, nCols;

    kNN knn;
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, -1, 1, -1);
    Dataset label = dataset.extract(0, -1, 0, 0);

    train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);
    double accuracy = knn.score(y_test, y_pred);
    std::cout << "Accuracy: " << accuracy << endl;
}

void tc10(){
    kDTree tree(2);
    tree.insert({5, 6});
    tree.insert({7, 3});
    tree.preorderTraversal();
    cout << endl;
    tree.remove({5, 6});
    tree.preorderTraversal();
    cout << endl;
    tree.insert({3, 2});
    tree.preorderTraversal();
    cout << endl;
}

void tc11(){
    kDTree tree(1);
    vector<vector<int>> p = {{6}, {4}, {2}, {5}, {6}, {8}, {4}, {3}, {2}, {5}, {6}, {6}, {7}, {6}, {5}, {6}, {6}, {6}, {5}, {4}};
    for (auto i : p){
        tree.insert(i);
    }
    tree.preorderTraversal();
    cout << endl;
    tree.remove({6});
    tree.preorderTraversal();
    cout << endl;
}

void tc12(){
    vector<vector<int>> p = {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {4,5}, {5,6}};
    vector<vector<int>> p1 = { {4,10}, {1,2}, {10,7}, {2,3}, {7,3}, {6,4}, {10,3}, {9,9}, {7,5}, {2,2}};
    kDTree tree;
    tree.buildTree(p1);
    tree.inorderTraversal();
    cout << endl;

    tree.preorderTraversal();
    cout << endl;
    //cout << tree.search({1, 2});
}
int main(int argc, const char *argv[])
{
    tc1();
    tc2();
    tc3();
    tc4();
    tc5();
    tc6();
    tc7();
    tc8();
    
    tc9();
    

    return 0;
}
