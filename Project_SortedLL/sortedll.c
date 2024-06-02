// ============================================================================
// File: sortedll.c (Spring 2024)
// ============================================================================
// This program allows the user to manipulate the contents of a list of
// integers in a singly-linked list. The list items are maintained in sorted
// ascending order, and duplicate values are permitted.
// ============================================================================

#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <ctype.h>
#include    "sortedll.h"


// ==== main ==================================================================
//
// ============================================================================

int     main(void)
{
    auto    int             intVal;
    auto    LNode           *headPtr = NULL;
    auto    char            buf[BUFLEN];
    auto    int             numItems;

    do  {
        // ask the user what they want to do and handle their choice
        DisplayMenu();
        printf("Please enter a selection: ");
        fgets(buf, BUFLEN, stdin);
        *buf = toupper(*buf);
        switch (*buf)
            {
            case   'A':
                printf("Please enter an integer value to add: ");
                fgets(buf, BUFLEN, stdin);
                if (1 != sscanf(buf, "%d", &intVal))
                    {
                    puts("Error reading the integer value...");
                    }
                else
                    {
                    headPtr = AddItem(headPtr, intVal);
                    }
                break;

            case   'R':
                if (NULL == headPtr)
                    {
                    puts("The list is already empty...");
                    }
                else
                    {
                    printf("Please enter an integer value to remove: ");
                    fgets(buf, BUFLEN, stdin);
                    if (1 != sscanf(buf, "%d", &intVal))
                        {
                        puts("Error reading the integer value...");
                        }
                    else
                        {
                        headPtr = RemoveItem(headPtr, intVal);
                        }
                    }
                break;

            case   'D':
                // display the current contents of the list
                numItems = DisplayList(headPtr);
                printf("*** main -- currently there %s %d node%s in the list...\n"
                                    , (numItems != 1) ? "are" : "is"
                                    , numItems
                                    , (numItems != 1) ? "s" : "");
                break;

            case   'F':
            case   'Q':
                // user wants to either clear the list or quit the program, so
                // release all nodes in the list
                numItems = FreeList(&headPtr);
                printf("*** main -- there %s %d node%s released...\n"
                                    , (numItems != 1) ? "were" : "was"
                                    , numItems
                                    , (numItems != 1) ? "s" : "");
                break;

            default:
                puts("Unrecognized option; please try again.");
                break;
            }

        // write out a blank line before next loop iteration
        puts("");

        } while ('Q' != *buf);

    puts("Thanks for playing!  Bye!!\n");
    return  0;

}  // end of "main"



// ==== AddItem ===============================================================
//
// This function inserts an item into the list by dynamically allocating a node
// to store the value and locating the correct position for the new item so
// that the list is maintained in ascending sorted order.
//
// Input:
//      headPtr [IN]        -- a pointer to the first node in the list
//
//      newItem [IN]        -- the new item to insert into the list
//
// Output:
//      A pointer to the head of the list.
// 
// ============================================================================

LNode*  AddItem(LNode  *headPtr, int  newItem)
{
	auto LNode *nodePtr;
	nodePtr = malloc(sizeof(LNode));
    if (nodePtr == NULL) { // check for failed memory allocation
		printf("Error! Memory allocation failed!\n");
		return headPtr;
	}
	else { 
		nodePtr->value = newItem; // set the value of the newly created node to be the number user entered
		if (headPtr == NULL || newItem < headPtr->value) { // Add the number if the list is empty or if the number is smaller than the smallest number of the list
			nodePtr->next = headPtr;
			headPtr = nodePtr;
			printf("*** AddItem: %d added to the list\n", newItem);
			return headPtr;
		}
		else {
			LNode *tempPtr = headPtr;
			LNode *prev = NULL;
			while (tempPtr != NULL && tempPtr->value < newItem) { // loop until current value is less than value 
				prev = tempPtr;
				tempPtr = tempPtr -> next;
			}
		nodePtr->next = tempPtr;
		prev->next = nodePtr;
    	printf("*** AddItem: %d added to the list\n", newItem);
    	return headPtr;
    	}
    }
}  // end of "AddItem"



// ==== DisplayList ===========================================================
//
// This function displays all of the values contained in the linked list to the
// standard output stream.
//
// Input:
//      headPtr [IN]        -- a pointer to the first node in the list
//
// Output:
//      The total number of nodes displayed is returned.
//
// ============================================================================

int     DisplayList(const LNode  *nodePtr)
{
    auto    int         counter = 0;

    // if the list is empty, indicate as such and return zero
    if (NULL == nodePtr)
        {
        return 0;
        }

    while (NULL != nodePtr)
        {
        printf("%d\n", nodePtr->value);
        nodePtr = nodePtr->next;
        counter++;
        }

    return counter;

}  // end of "DisplayList"



// ==== DisplayMenu ===========================================================
//
// This function displays the menu to stdout.
//
// Input:
//      Nothing
//
// Output:
//      Nothing
//
// ============================================================================

void    DisplayMenu(void)
{
    // write out a leading blank line, followed by menu items
    puts("A)dd a value");
    puts("R)emove a value");
    puts("D)isplay the list");
    puts("F)ree the list");
    puts("Q)uit");

}  // end of "DisplayMenu"



// ==== FreeList ==============================================================
//
// This function traverses the linked list and releases the memory allocated
// for each individual node, and the caller's head node pointer is set to NULL.
//
// Input:
//      headPtr [IN/OUT]    -- the address of the caller's head node pointer
//
// Output:
//      The total number of nodes released is returned.
//
// ============================================================================

int     FreeList(LNode  **headPtr)
{
	LNode *currentNode = *headPtr;
	auto int temp;
	while (currentNode != NULL) { // free all allocated memory
		free(currentNode);
		currentNode = currentNode->next;
		temp++;
	}
	*headPtr = NULL; // set headptr back to null
	return temp;
}  // end of "FreeList"



// ==== RemoveItem ============================================================
//
// This function removes an item from the list.  If the target item is located
// in the list, the memory allocated for its node is released and any adjacent
// nodes are joined so as not to break the list.
//
// Input:
//      headPtr [IN]        -- a pointer to the first node in the list
//
//      target [IN]         -- the item to remove
//
// Output:
//      A pointer to the head of the list
//
// ============================================================================

LNode*  RemoveItem(LNode  *headPtr, int  target)
{
	if (headPtr == NULL) { // Trying to remove node from empty list
		printf("The list is already empty...\n");
	}
    LNode *currentNode = headPtr;
    LNode *prevNode = NULL;
    while (currentNode != NULL) { // traverse until end of list
    	if (currentNode->value == target) {
    		if (prevNode == NULL) { // removing the first node
    			headPtr = currentNode->next;
    			free(currentNode);
    			printf("*** RemoveItem: %d removed from the list...\n", target);
    			return headPtr;
    		}
    		else if (currentNode->next == NULL) { // removing last node
    			free(currentNode);
    			prevNode->next = NULL;
    			printf("*** RemoveItem: %d removed from the list...\n", target);
    			return headPtr;
    		}
    		else { // removing a node that is between 2 other nodes
    			prevNode->next = currentNode->next;
    			free(currentNode);
    			printf("*** RemoveItem: %d removed from the list...\n", target);
    			return headPtr;
    		}
    	}
    	else { // traverse the list
    		prevNode = currentNode;
    		currentNode = currentNode->next;
    	}
    }
    printf("*** RemoveItem: %d was not found in the list...\n", target);
    return headPtr;
}  // end of "RemoveItem"
