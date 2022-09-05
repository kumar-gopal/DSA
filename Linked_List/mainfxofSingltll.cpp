#include "singlyLL.cpp"

int main()
{
    singlyLL sll;
    sll.insertAtFirstNode(1);
    sll.insertAtFirstNode(2);
    sll.insertAtLastNode(3);
    sll.insertAtGiventNode(20,2);
    sll.viewData();
    sll.DeleteAtGivenNode(30);
    sll.viewData();
}