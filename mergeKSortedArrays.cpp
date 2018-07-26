struct MinHeapNode
{
    int element;
    int i; //index of arr
    int j; //index of next element from this arr
};

struct MinHeap
{
    MinHeapNode * harr;
    int heapsize;
public:
    MinHeap(MinHeapNode arr[], int size);
    int left(int i)
    {
        return (2*i+1);
    }
    int right(int i)
    {
        return (2*i+2);
    }
    void minHeapify(int i);
    MinHeapNode getMin() {return harr[0];}
    void replaceRoot(MinHeapNode x){
        harr[0] = x;
        minHeapify(0);
    }
};
MinHeap :: MinHeap(MinHeapNode arr[], int size)
{
    heapsize = size;
    harr = arr;
    for(int i = (heapsize-1)/2; i>= 0; i--)
        minHeapify(i);
}
void MinHeap:: minHeapify(int i)
{
    int smallest = i;
    int l = left(i);
    int r = right(i);
    if(l < heapsize and harr[l].element < harr[smallest].element)
        smallest = l;
    if(r < heapsize and harr[r].element < harr[smallest].element)
        smallest = r;
    if(smallest != i)
    {
        swap(harr[smallest],harr[i]);
        minHeapify(smallest);
    }
    
}
int *mergeKArrays(int arr[][N], int k)
{
    int * ans = new int[k*k];
    MinHeapNode * harr = new MinHeapNode[k];
    for(int i = 0; i < k; i++)
    {
        harr[i].element = arr[i][0];
        harr[i].i = i;
        harr[i].j = 1; //next index will be 1 for all
    }
    MinHeap h(harr,k);
    for(int index = 0; index < k*k; index++)
    {
        MinHeapNode curr = h.getMin();
        ans[index] = curr.element;
        
        if(curr.j < k)
        {
            curr.element = arr[curr.i][curr.j];
            curr.j += 1;
        }
        else
            curr.element = INT_MAX;
        h.replaceRoot(curr);
    }
    return ans;
//code here
}
