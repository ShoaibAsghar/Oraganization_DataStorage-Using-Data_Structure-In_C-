// project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
//Queue
template<class datatype>
struct Node
{
    datatype data;
    Node* next;
};
template<class datatype>
class queue
{
private:
    Node<datatype>* front;
    Node<datatype>* rear;
    int size;
public:
    queue();
    bool isEmpty();
    void makeNull();
    datatype dequeue();
    void enqueue(datatype);
    void display();
    int Que_size() { return size; }
};
template<class datatype>
queue<datatype>::queue()
{
    front = NULL;
    rear = NULL;
    size = 0;
}
template<class datatype>
bool queue<datatype>::isEmpty()
{
    if (front)
        return false;// if front is not NULL it means there is some data in it
    else
        return true;
}
template<class datatype>
void queue<datatype>::makeNull()
{
    while (!isEmpty())
    {
        dequeue();  //we delete nodes in queue untill it will empty
    }
}
template<class datatype>
datatype queue<datatype>::dequeue()
{
    Node<datatype>* nodee;
    datatype data;
    if (isEmpty())
    {
        cout << "The Queue is empty.\n";
    }
    else
    {
        data = front->data;

        nodee = front->next;
        delete front;
        front = nodee;
        size--;
        if (front == NULL)
        {
            rear = NULL;
        }
        return data;
    }
}
template<class datatype>
void queue<datatype>::enqueue(datatype val)
{
    Node<datatype>* nodee = new Node<datatype>;
    nodee->data = val;
    nodee->next = NULL;
    if (isEmpty())
    {
        front = nodee;
        rear = nodee;
    }
    else
    {
        rear->next = nodee;
        rear = nodee;
    }
    size++;
}

//Stack Implementation
template<class T1>
struct NODE
{
    T1 element;
    NODE* next;
};
template<class T1>
class Stack
{
    NODE<T1>* Top;
public:

    Stack() { Top = NULL; }		//default constructor
    void push(T1 ele);
    T1 pop();
    bool isEmpty();
    T1 get_top() { return Top->element; }
};
template<class T1>
void Stack<T1>::push(T1 ele)
{
    if (isEmpty())
    {
        NODE<T1>* curr = new NODE<T1>;
        curr->element = ele;
        curr->next = NULL;
        Top = curr;
    }
    else
    {
        NODE<T1>* curr = new NODE<T1>;
        curr->next = Top;
        Top = curr;
        Top->element = ele;
    }
}
template<class T1>
T1 Stack<T1>::pop()
{
    T1 val = NULL;
    if (Top)
    {
        NODE<T1>* temp;
        temp = Top;
        val = temp->element;
        Top = Top->next;
        delete temp;
    }
    else
    {
        //cout << "Underflow\n";
    }
    return val;
}
template<class T1>
bool Stack<T1>::isEmpty()
{
    if (Top != NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//Linked List
//template<class datatype>
struct node
{
    int data;  //template base varaible 
    node* next;
};
//template<class datatype>
class AdjList
{
private:
    node* head;
public:
    AdjList() { head = NULL; }
    void set_head(node*& temp) { head = temp; }
    node* get_head() { return head; }
    void make_null()
    {
        node* currnode = head;
        node* prevnode = NULL;
        while (head->next != NULL)
        {
            while (currnode->next != NULL)
            {
                prevnode = currnode;
                currnode = currnode->next;
            }
            prevnode->next = currnode->next;
            delete currnode;
            currnode = head;
        }
        delete head;
        head = NULL;
    }
    void insert(int d)
    {
        if (head == NULL)
        {
            node* currnode = new node;
            head = currnode;
            head->data = d;
            head->next = NULL;
        }
        else
        {
            node* currnode = head;
            while (currnode->next != NULL)
            {
                currnode = currnode->next;  //locating the end
            }
            //Creating new node and storing data in it
            node* newnode = new node;
            newnode->data = d;
            //now add node in linked list at end
            newnode->next = NULL; //storing Null at end
            currnode->next = newnode;       //now adding new node at end in list
        }
    }
    bool remove(int id)
    {
        node* curr_node = head;
        node* prev_node = NULL;
        while (curr_node && curr_node->data != id)
        {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
        if (curr_node)
        {
            node* temp = curr_node;
            prev_node->next = temp->next;
            delete curr_node;
            return true;
        }
        else
            cout << "Record does not exist";
        return false;
    }
    void display()
    {
        node* currnode = head;
        while (currnode != NULL)
        {
            if (currnode == head)
                cout << currnode->data << " --> ";
            else
                cout << currnode->data << ", ";
            currnode = currnode->next;  //locating the end
        }
    }
};
//template<class datatype>
class Graph
{
private:
   
    int size;
    int total_edges;
    int total_nodes;
public:
    AdjList* array;
    Graph(int size)
    {
        this->size = size;
        total_edges = 0;
        total_nodes = 0;
        array = new AdjList[size];
    }
    Graph()
    {
        array = NULL;
        size = 0;
        total_edges = 0;
        total_nodes = 0;
    }
    int get_size() { return this->size; }
    void make_array(int size)
    {
        this->size = size;
        total_edges = 0;
        total_nodes = 0;
        array = new AdjList[size];
    }
    bool is_empty()
    {
        if (array[0].get_head() == NULL)
        {
            return true;
        }
        return false;
    }
    int get_edges()
    { return total_edges; }
    int get_nodes()
    { return total_nodes; }
    void addEdge(int src, int dest)
    {
        int i = 0;// curr_index;
        for (i = 0; i < size; i++)
        {
            if (array[i].get_head() == NULL)
            {
                array[i].insert(src);
                array[i].insert(dest);
                //As a new node has added in array of linked lists so we increment in total_nodes
                total_nodes++;
                total_edges++;
                return;
            }
            else if (array[i].get_head()->data == src)
            {
                array[i].insert(dest);
                //As an existing node has updated in array of linked lists so we increment in total_edges
                total_edges++;
                return;
            }
        }
    }
    void showGraphStructure()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " => ";
            array[i].display();
            cout << endl;
        }
    }
    //This function of getting index wrt ID would be used when graph is compltely created
    int get_index(int value)
    {
        for (int i = 0; i < size; i++)
        {

            if (this->array[i].get_head() != NULL && value == array[i].get_head()->data)
            {
                return i;
            }
        }
        cout << "No Node exists in graph with this ID: " << value << endl;
        return -1;
    }
    int in_degree(int num)
    {
        
        bool present = true;
        if (this->get_index(num) == -1)
        {
            present = false;
        }
        int indegree = 0;
        node* temp = NULL;
        if (present)
        {
            for (int i = 0; i < this->size; i++)
            {
                if (array[i].get_head()->data != num)
                {
                    temp = array[i].get_head();
                    while (temp != NULL)
                    {
                        if (temp->data == num)
                        {
                            indegree++;
                        }
                        temp = temp->next;
                    }
                }
            }
            return indegree;
        }
        return -1;
        
    }
    int out_degree(int num)
    {
        int outdegree = 0;
        int index = get_index(num);
        bool present = true;
        if (index == -1)
        {
            present = false;
        }
        if (present)
        {
            node* temp = NULL;
            temp = array[index].get_head();
            while (temp->next != NULL)
            {
                outdegree++;
                temp = temp->next;
            }
            return outdegree;
        }
        else
            return -1;
    }
    bool is_source(int num)
    {
        if (this->in_degree(num) == 0 && this->out_degree(num) >= 1)
        {
            cout << "The given node is Source node.\n";
            return true;
        }
        cout << "The given node is not a Source node.\n";
        return false;
    }
    bool is_sink(int num)
    {
        if (this->out_degree(num) == 0)
        {
            cout << "The given node is Sink node.\n";
            return true;
        }
        cout << "The given node is not a Sink node.\n";
        return false;
    }
    void make_directedgraph(int src,int dest)
    {
        int index_dest = -1;
        int index_src = -1;
        for (int i = 0; i < size && this->array[i].get_head() != NULL; i++)
        {
            if (dest == array[i].get_head()->data)
            {
                index_dest = i;
            }
            if (src == array[i].get_head()->data)
            {
                index_src = i;
            }
        }
        bool present = false;
        if(index_dest != -1)
        {
            node* temp = this->array[index_dest].get_head();
            while(temp != NULL)
            {
                if (temp->data == src)
                    present = true;
                temp = temp->next;
            }
            if (!present)
                this->addEdge(src, dest);
            else if(index_src == -1)//if source is not present then we add in graph
            {
                int i = 0;// curr_index;
                for (i = 0; i < this->size; i++)
                {
                    if (this->array[i].get_head() == NULL)
                    {
                        array[i].insert(src);
                        //As a new node has added in array of linked lists so we increment in total_nodes
                        this->total_nodes++;
                        return;
                    }
                }
            }
        }
        else if (index_dest == -1)
        {
            this->addEdge(src, dest);
        }
    }

    //Deabth Fisrt Traversal
    int DFS(int s)
    {
        int counter = 0;
        bool* visited = new bool[this->size];
        bool* status = new bool[this->size];
        for (int i = 0; i < this->size; i++)
        {
            visited[i] = false;
            status[i] = false;
        }
        // AdjList<int> 
        Stack<node*> q;
        visited[s] = true;
        int currvertex;
        q.push(array[s].get_head());
        node* temp = NULL;
        while (!q.isEmpty())
        {
            temp = q.get_top();
            currvertex = this->get_index(temp->data);
            if (!status[currvertex])
            {
                status[currvertex] = true;
                counter++;
            }

            temp = this->array[currvertex].get_head()->next;
             while (temp != NULL)
                {
                    currvertex = this->get_index(temp->data);
                    if (!visited[currvertex])
                    {
                        visited[currvertex] = true;
                        q.push(temp);
                        break;
                    }
                    temp = temp->next;
                }
             if (temp == NULL)
             {
                 q.pop();
             }
        }
        return counter;
    }
    //Breadth Fisrt Traversal
    int* BFS(int s)
    {
        int* reachable = new int[this->size];
        bool* visited = new bool[this->size];
        for (int i = 0; i < this->size; i++)
        {
            visited[i] = false;
        }

        // AdjList<int> 
        queue<node*> q;
        visited[s] = true;
        int currvertex;
        q.enqueue(array[s].get_head());
        node* temp = NULL;
        int node_index = 0;
        while (!q.isEmpty())
        {
            temp = q.dequeue();
           //Adding nodes data in array which will return at end
            reachable[node_index] = temp->data;
            node_index++;
            currvertex = this->get_index(temp->data);
            temp = this->array[currvertex].get_head()->next;
            while (temp != NULL)
            {
                currvertex = this->get_index(temp->data);
                if (!visited[currvertex])
                {
                    visited[currvertex] = true;
                    q.enqueue(temp);
                }
                temp = temp->next;
            }
        }
        return reachable;
    }
    void is_bridge(int node1, int node2)
    {
      int t_nodes = this->DFS(0);
      cout << this->DFS(0);
        int currvertex = this->get_index(node1);
        node* temp = this->array[currvertex].get_head();
        currvertex = this->get_index(node2);
        node* temp2 = this->array[currvertex].get_head();
        node* temp3 = NULL;
        while (temp != NULL)
        {
            if (temp->next->data == node2)
            {
                temp3 = temp->next;
                temp->next = temp3->next;
                delete temp3;
                break;
            }
            temp = temp->next;
            
        }
        while (temp2 != NULL)
        {
            if (temp2->next->data == node1)
            {
                temp3 = temp2->next;
                temp2->next = temp3->next;
                delete temp3;
                break;
            }
            temp2 = temp2->next;
            
        }
        cout << endl;
        if (this->DFS(0) == t_nodes)
            cout << "\nThis edge is not a  bridge edge.\n";
        else
            cout << "\nThis edge is a bridge edge.\n";
    }
    void is_articulationnode(int num)
    {
        int currvertex = this->get_index(num);
        node* temp = NULL;
        node* temp2 = NULL;
        if (currvertex != -1)
        {
            for (int i = 0; i < this->size; i++)
            {
                if (i != currvertex)
                {
                    temp = this->array[i].get_head();
                    while (temp->next != NULL)
                    {
                        if (temp->next->data == num)
                        {
                            temp2 = temp->next;
                            temp->next = temp2->next;
                            delete temp2;
                            break;
                        }
                        temp = temp->next;
                    }
                }
            }
            //delete the linked list of given node
            this->array[currvertex].make_null();
            if (currvertex == 0)
            {
                if (this->DFS(1) < this->total_nodes - 1)
                    cout << "This Node is an Articulation point.\n";
                else
                    cout << "This Node is not an Articulation point.\n";
            }
            else
            {
                if (this->DFS(0) < this->total_nodes - 1)
                    cout << "This Node is an Articulation point.\n";
                else
                    cout << "This Node is not an Articulation point.\n";
            }
        }
    }
    void calculate_degrees(int** degree)
    {
        int node_id;
        //we store in-degree in 2D array at column 0 and out-degree at coloumn 1
        for (int i = 0; i < this->size; i++)
        {
            node_id = this->array[i].get_head()->data;
            for (int j = 0; j < 2; j++)
            {
                //when j = 0 we calculate in degree 
                if (j == 0)
                    degree[i][j] = this->in_degree(node_id);
                else if (j == 1)
                    degree[i][j] = this->out_degree(node_id);
            }
        }
    }
    bool is_isolated(int** degrees,int id)
    {
        int currvertex = this->get_index(id);
        if (degrees[currvertex][0] == 0 && degrees[currvertex][1] == 0)
        {
            cout << "The given node "<<id<<" is an Isolated node.\n";
            return true;
        }
        cout << "The given node " << id << " is not an Isolated node.\n";
        return false;
    }
    //Second set of Tasks
    void indegree_distribution(int** degrees)
    {
        int max_in = 0;
        int in_distribution = 0;
        float distribution;
        for (int i = 0; i < this->size; i++)
        {
            if (max_in < degrees[i][0])
                max_in = degrees[i][0];
        }
        //Printing heading 
        cout << "\n     ***************************************************     \n"
            << "***************** IN_Degree Distribution ******************\n"
            << "     ***************************************************     \n\n"
            << "Total Nodes in Graph is " << this->total_nodes << endl
            << "  In Degree  " << " Total Nodes with this in-degree   Distribution\n";
        for (int in = 0; in <= max_in; in++)
        {
            for (int j = 0; j < this->size; j++)
            {
                if (degrees[j][0] == in)
                    in_distribution++;
            }
            if (in_distribution != 0)
            {
                //we convert total indegree count and total nodes into float then divide it
                distribution = static_cast<float>(in_distribution) / static_cast<float>(this->total_nodes);
                //Now printing calculated distribution of a particular degree
                cout << "   " << in << "                            " << in_distribution <<"                "<<distribution<< endl;
                in_distribution = 0;
            }
        }
    }
    void outdegree_distribution(int** degrees)
    {
        int max_out = 0;
        int out_distribution = 0;
        float distribution;
        for (int i = 0; i < this->size; i++)
        {
            if (max_out < degrees[i][1])
                max_out = degrees[i][1];
        }
        //Printing heading 
        cout << "\n     ***************************************************     \n"
            << "***************** OUT_Degree Distribution ******************\n"
            << "     ***************************************************     \n\n"
            << "Total Nodes in Graph is " << this->total_nodes << endl
            << "  Out Degree  " << " Total Nodes with this out-degree   Distribution\n";
        for (int out = 0; out <= max_out; out++)
        {
            for (int j = 0; j < this->size; j++)
            {
                if (degrees[j][1] == out)
                    out_distribution++;
            }
            if (out_distribution != 0)
            {
                distribution = static_cast<float>(out_distribution) / static_cast<float>(this->total_nodes);
                //Now printing calculated distribution of a particular degree
                cout << "   " << out << "                            " << out_distribution << "                  " << distribution << endl;
                out_distribution = 0;
            }
        }
    }
    AdjList IN(int num)
    {
        AdjList In_of_index;
        node* temp = NULL;
        for (int i = 0; i < this->size; i++)
        {
            if (array[i].get_head()->data != num)
            {
                temp = array[i].get_head();
                while (temp != NULL)
                {
                    if (temp->data == num)
                    {
                        In_of_index.insert(array[i].get_head()->data);
                    }
                    temp = temp->next;
                }
            }
        }
        return In_of_index;
    }
    AdjList OUT(int num)
    {
        AdjList out_of_index;
        node* temp = NULL;
        int index = this->get_index(num);
        out_of_index = this->array[index];
        out_of_index.set_head(this->array[index].get_head()->next);
        return out_of_index;
    }
    AdjList SCC()
    {
        AdjList scc,in,out;
        node* temp_in = NULL;
        node* temp_out = NULL;
        for (int i = 0; i < this->size; i++)
        {
            in = this->IN(this->array[i].get_head()->data);
            out = this->OUT(this->array[i].get_head()->data);
            temp_in = in.get_head();
            
            while (temp_in != NULL)
            {
                temp_out = out.get_head();
                while (temp_out != NULL)
                {
                    if (temp_in->data == temp_out->data)
                    {
                        scc.insert(temp_in->data);
                        break;
                    }
                    temp_out = temp_out->next;
                }
                temp_in = temp_in->next;
            }
        }
        this->unique(scc);
        node* temp = scc.get_head();
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        return scc;
    }
    void unique(AdjList& scc)
    {
        node* temp = scc.get_head();
        node* temp2 = NULL;
        while (temp->next != NULL)
        {
            temp2 = temp->next;
            while (temp2 != NULL)
            {
                if (temp->data == temp2->data)
                {
                    temp2->data = -1;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        temp = scc.get_head();
        while (temp != NULL)
        {
            if (temp->data == -1)
            {
                scc.remove(-1);
                temp = scc.get_head();
            }
            else
                temp = temp->next;
        }
    }

};

void make_undirectedgraph(Graph& g,Graph& g_dir, string path)
{
    ifstream FileObj(path);
    if (!FileObj.is_open())
    {
        cout << "file failed to open" << endl;
        return;
    }
   
    string line;
    string mystring;
    string nodes, edges;
    string data_N, data_E;
    int line_no = 0;
    while (!FileObj.eof() && getline(FileObj, line, '\n'))
    {
        //getline from the csv into line variable
        stringstream objj(line);        //Store the data of csv file into appropriat variables 
        //No. of nodes will get 
        if (line_no >= 4)
        {
            getline(objj, data_N, '\t');
            getline(objj, data_E, '\n');
            //Creating node and edges for undirected graph
            g.addEdge(stoi(data_N), stoi(data_E));
            //Creating node and edges for directed graph
           g_dir.make_directedgraph(stoi(data_N), stoi(data_E));
        }
        else if (line_no == 0 || line_no == 1 || line_no == 3)
        {
            
            line_no++;
        }
        else if (line_no == 2)
        {
            //No. of edges will get
            for (int i = 0; i < 3; i++)
                getline(objj, nodes, ' ');
            //No. of edges will get 
            for (int i = 0; i < 2; i++)
                getline(objj, edges, ' ');
            //Making dynamic array of size given in file
            g.make_array(stoi(nodes));
            g_dir.make_array(stoi(nodes));
            line_no++;
        }
    }
}

int main()
{
    //g1 is undirected graph and g2 is directed graph
    Graph g1,g2;
  

    int choice2;

    cout << "              ****************************************************************                   " << endl;
    cout << "                      Welcome To  Network Analysis using Graph project                           " << endl;
    cout << "*************************************************************************************************" << endl;
    cout << "              ****************************************************************                   " << endl;
    cout << "******************************************  Main Menu  ******************************************" << endl;
    cout << "              ****************************************************************                   " << endl << endl;
    cout << "****************  For which file  do you make a graph  *******************************************" << endl;
    cout << "              ****************************************************************                   " << endl;
    cout << "****************  Enter 1 for Reading File [CA-GRQc.txt] it may take 1 minute  ******************" << endl;
    cout << "              ****************************************************************                   " << endl;

    cout << "*************  Enter 2 for Reading File [CA-AstroPh.txt] it may take more then 10 minute  *******" << endl;
    cout << "              ****************************************************************                   " << endl;
    cout << "Enter your choice between (1-2): ";
    cin >> choice2;
    while (choice2 < 1 || choice2 >2)
    {
        cout << "Error! Please Enter correct choice between (1-2) for file reading on your choice: " << endl;
        cin >> choice2;
    }
    //Making of graph with respective file
    if (choice2 == 1)
    {
        // make_undirectedgraph(g1, g2, "D:/Visual_studio/project/input.txt");
        make_undirectedgraph(g1,g2, "D:/Visual_studio/project/ca-GrQc.txt/CA-GrQc.txt");
    }
    else if (choice2 == 2)
    {
        make_undirectedgraph(g1, g2, "D:/Visual_studio/project/ca-AstroPh/CA-AstroPh.txt");
    }
    //Calculating degress
    int** degrees = new int* [g2.get_size()];
    for (int i = 0; i < g2.get_size(); i++)
    {
        degrees[i] = new int[2];
    }
    g2.calculate_degrees(degrees);
    cout << "**************************************  First Set of Tasks  *************************************" << endl;
    cout << "              ****************************************************************                   " << endl;

    cout << "*************  Enter 1 To find and Display The total number of nodes in a graphs  ***************" << endl;
    cout << "              ****************************************************************                   " << endl;

    cout << "*************  Enter 2 To find and Display The total number of edges in a graphs  ***************" << endl;
    cout << "              ****************************************************************                   " << endl;

    cout << "******Enter 3 To find weather the entered node is source or not.*******" << endl;
    cout << "** In this Case user Enter a node and program tell us weather the entered node is source or not *" << endl;
    cout << "              ****************************************************************                   " << endl;

    cout << "**************  Enter 4 To find weather the entered node is sink or not.  ***********************" << endl;
    cout << "**  In this Case user Enter a node and program tell us weather the entered node is sink or not **" << endl;
    cout << "              ****************************************************************                   " << endl;

    cout << "*************  Enter 5 To find weather the entered node is isolated node or not *****************" << endl;
    cout << "* In this Case user Enter a node and program tell us weather the entered node is isolated or not " << endl;
    cout << "              ****************************************************************                   " << endl;

    cout << "***********  Enter 6 To find weather the entered node is bridge edge node or not ****************" << endl;
    cout << "In this Case user Enter a node and program tell us weather the entered node is bridge edge or not" << endl;

    cout << "              ****************************************************************                   " << endl;

    cout << "*****Enter 7 To find weather the entered node is articulation nodes or not.****" << endl;
    cout << "In this Case user Enter a node and program tell us weather the entered node is articulated or not" << endl;
    cout << "              ****************************************************************                   " << endl;
    cout << "              ****************************************************************                   " << endl << endl;

    cout << "******************************Second Set of Tasks************************************************" << endl;
    cout << "              ****************************************************************                   " << endl;
    cout << "              ****************************************************************                   " << endl;
    cout << "************  Enter 8 To Display The in-degree distribution in the form of a table  *************" << endl;
    cout << "              ****************************************************************                   " << endl;

    cout << "************  Enter 9 To Display The out-degree distribution in the form of a table  ************" << endl;
    cout << "              ****************************************************************                   " << endl;
    cout << "***  Enter 10 To Display The size of the largest strongly connected component(SSC) in a graph  **" << endl;
    cout << "              ****************************************************************                   " << endl;
    cout << "              ****************************************************************                   " << endl;
    cout << "********************  Enter 0 To Exit the Program  ************************" << endl;


    int choice = -1;;
    while (choice != 0)
    {
        cout << "Enter your choice between (1-10): ";
        cin >> choice;

        while (choice < 0 || choice >10)
        {
            cout << "Error! Please Enter correct choice between (1-10): " << endl;
            cin >> choice;
        }
        switch (choice)
        {
        case 0:
             return 0;
        case 1:
        {
            //call function to Display total nodes  
            cout << g1.get_nodes()<<endl;
        }
        break;
        case 2:
        {
            //call function to Display The total number of edges in a graphs
            cout << g1.get_edges() << endl;
        }
        break;

        case 3:
        {
            //call function to finf  weather the entered node is source or not
            int num;
            cout << "Enter node id: ";
            cin >> num;
            g2.is_source(num);
        }
        break;
        case 4:
        {
            //call function to find weather the entered node is sink or not
            int num;
            cout << "Enter node id: " ;
            cin >> num;
            g2.is_sink(num);
        }
        break;
        case 5:
        {
            //call function to find weather the entered node is isolated node or not  
            int num;
            cout << "Enter node id: ";
            cin >> num;
            g2.is_isolated(degrees,num);
        }
        break;
        case 6:
        {
            //call function  To find weather the entered node is bridge edge node or not
            int num;
            cout << "Enter node id: ";
            cin >> num;
            int i = g1.get_index(num);
            node* temp = g1.array[i].get_head();
            while (temp != NULL)
            {
                cout<<temp->data <<" ";
                temp = temp->next;
            }
            cout << "\nEnter 2nd number from above list to remove edge :";
            int num2;
            cout << "Enter node id: ";
            cin >> num2;
            g1.is_bridge(num,num2);
        }
        break;
        case 7:
        {
            //call function to find weather the entered node is articulation nodes or not
            int num;
            cout << "Enter node id: ";
            cin >> num;
            g1.is_articulationnode(num);
        }
        break;

        case 8:
        {
            //call function to Display The in-degree distribution in the form of a table
            g2.indegree_distribution(degrees);
        }
        break;

        case 9:
        {
            //call function to Display The out-degree distribution in the form of a table
            g2.outdegree_distribution(degrees);
        }
        break;
        case 10:
        {
            //call function to Display The size of the largest strongly connected component(SSC)
            g1.SCC();
        }
        break;

        default:
            cout << "Invalid: Input" << endl;

        }
    }
    return 0;
}
