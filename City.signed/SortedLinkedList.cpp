#include "SortedLinkedList.h"

#include<iomanip>

/***** Complete this class. *****/
//Constructor called
SortedLinkedList::SortedLinkedList(): head(nullptr)
{

}

SortedLinkedList::~SortedLinkedList()
{

}
//Insert function to enter file data into linked list in a sorted fashion
void SortedLinkedList::insert(Node *node){

	Node *p=head;


	if(head==nullptr || *head>*node)
	{
		node->next = head;
		head = node;
	}
	else
	{

		while((p->next!= nullptr) && (*node>*(p->next)))
		{
			p = p->next;
		}

		node->next=p->next;
		p->next=node;

	}




}

//'<<' operator overloaded to print entire list
ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{


//array containg spaces and data from the list
	char a[49][117];



//enter spaces

		for(int i=0;i<49;i++)
		{      int j=0;
		
			while(j<117)
          {
				a[i][j]=' ';
            j++;
			}
		}
		Node *p=list.head;
		

		Node *q=list.head;
		
	//Markup and enter data at required locations
		while (p->next!= nullptr)
		{
			if(p->get_row()==p->next->get_row() && p->get_col()==p->next->get_col())
			{

				p->next=p->next->next;

			}

			a[p->get_row()][p->get_col()]='#';


			p=p->next;

		}
        //print marked up array with the help of output overloading of node 
			for(int i=0;i<49;i++)
				{
					for(int j=0;j<117;j++)
					{

						if(a[i][j]=='#')
						{
						
							
							 if(q->get_row()==43 && q->get_col()==84)
							   {
							      q=q->next;
							   }
                         	outs<<*q;
							if(q->get_name()!="")
							{ 
							  
							   
							   
								j=j+(q->get_name().length())+3;
								while((q->next->get_col()<=j)&&(q->get_row()==q->next->get_row()))
								{
									q=q->next;
								}

							}

							q=q->next;
						}
						else
						{
							outs<<' ';
						}
						a[48][89]='#';
					}
					if(i<48)
					{
					   cout<<endl;
					}
				}


	return outs;
}