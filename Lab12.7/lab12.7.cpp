#include <iostream>

using namespace std;

struct Elem {
    Elem* link;
    int info;
};

void Insert(Elem*& L, int value) {
    Elem* tmp = new Elem{ nullptr, value };
    if (L != nullptr) {
        Elem* p = L;
        while (p->link != L) {
            p = p->link;
        }
        p->link = tmp;
        tmp->link = L;
    }
    else {
        L = tmp;
        L->link = L;
    }
}

Elem* RemoveThird(Elem*& L, int& count) {
    Elem* removedList = nullptr;
    Elem* removedTail = nullptr;
    count = 0;

    if (!L || L->link == L || L->link->link == L) {
        Elem* current = L;
        while (current) {
            Elem* next = (current->link == current) ? nullptr : current->link;
            if (L == current) {
                L = next;
            }
            if (!removedList) {
                removedList = removedTail = new Elem{ nullptr, current->info };
            }
            else {
                removedTail->link = new Elem{ nullptr, current->info };
                removedTail = removedTail->link;
            }
            delete current;
            count++;
            if (next == current || next == nullptr) break;
            current = next;
        }
        return removedList;
    }

    Elem* current = L;
    Elem* prev = nullptr;
    int step = 1;

    while (L && L->link != L && L->link->link != L) {
        if (step == 3) {
            if (prev) {
                prev->link = current->link;
            }
            if (current == L) {
                L = current->link;
            }

            if (!removedList) {
                removedList = removedTail = new Elem{ nullptr, current->info };
            }
            else {
                removedTail->link = new Elem{ nullptr, current->info };
                removedTail = removedTail->link;
            }
            delete current;
            count++;

            current = prev->link;
            step = 1; 
        }
        else {
            prev = current;
            current = current->link;
            step++;
        }
    }

    return removedList;
}

void PrintList(Elem* L) {
    if (L == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Elem* first = L;
    do {
        cout << L->info << " ";
        L = L->link;
    } while (L != first);
    cout << endl;
}

void PrintAndClearList(Elem* L) {
    cout << "Removed elements: ";
    while (L != nullptr) {
        cout << L->info << " ";
        Elem* temp = L->link;
        delete L;
        L = temp;
    }
    cout << endl;
}

int main() {
    Elem* L = nullptr;
    for (int i = 1; i <= 10; i++) {
        Insert(L, i);
    }
    cout << "Original List: ";
    PrintList(L);

    int removedCount;
    Elem* removedList = RemoveThird(L, removedCount);

    cout << "Remaining List after removing every third element: ";
    PrintList(L);

    PrintAndClearList(removedList);
    cout << "Number of removed elements: " << removedCount << endl;

    return 0;
}