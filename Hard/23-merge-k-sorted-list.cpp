class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                temp->next = a;
                a = a->next;
            }
            else {
                temp->next = b;
                b = b->next;
            }

            temp = temp->next;
        }

        if (a != nullptr) {
            temp->next = a;
        }
        else {
            temp->next = b;
        }

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        while (lists.size() > 1) {
            vector<ListNode*> merged;

            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* a = lists[i];
                ListNode* b = nullptr;

                if (i + 1 < lists.size()) {
                    b = lists[i + 1];
                }

                merged.push_back(mergeTwoLists(a, b));
            }

            lists = merged;
        }

        return lists[0];
    }
};
