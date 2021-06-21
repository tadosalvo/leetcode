void deleteNode(ListNode* node) {
    *node = *node->next;
}

void deleteNode(ListNode* node) {
    auto next = node->next;
    *node = *next;
    delete next;
}