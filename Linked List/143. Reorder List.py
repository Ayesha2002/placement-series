# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        store = []
        temp= head
        while temp:
            store.append(temp)
            temp=temp.next

        newhead = store[0]
        tail = None
        for i in range(len(store)//2):
            store[i].next=store[-1-i]
            store[i].next.next=store[i+1]
            tail=store[i].next.next
        if tail:
            tail.next = None
        head=newhead
