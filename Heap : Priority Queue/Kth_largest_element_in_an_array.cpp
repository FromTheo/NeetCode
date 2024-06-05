#include <iostream>
#include <vector> 
#include <queue>      //std::priority_queue

using namespace std; 

/* -------- Subject -------- 
Given an unsorted array of integers nums and an integer k, return the kth largest element in the array.
By kth largest element, we mean the kth largest element in the sorted order, not the kth distinct element.
Follow-up: Can you solve it without sorting? */ 

/* -------- Explanation --------
Nous allons créer une priority_queue construite par défaut et ajoutons les valeurs de nums.
Crééons un vecteur collection et remplissons le avec les valeurs de Q. Il reste à retourner le dernier élément de collection. 
On aurait pu éviter de construire un vecteur (et d'éviter push_back qui est très couteux en terme de mémoire) en utilisant un compteur 
et faire :  
    int compteur = 1; 
    while(compteur < k )
    {
        ...
        compteur++;
    }
    return Q.top 
*/

int findKthLargest(vector<int>& nums, int k) 
{
    priority_queue<int> Q; 
    for(const int& i : nums)
    {
        Q.push(i); 
    }
    vector<int> collection;
    while(collection.size() < k)
    {
        int number = Q.top(); 
        /* If we wanted to not have identical numbers :
        auto it = std::find(collection.begin(), collection.end(), number);
        if(it == collection.end()) collection.push_back(number); */ 
        collection.push_back(number); 
        Q.pop(); 
    }
    return collection.back();
}

int main()
{
    vector<int> nums1{2,3,1,5,4}, nums2{2,3,1,1,5,5,4};
    int k1 = 2, k2 = 3;
    cout << findKthLargest(nums1, k1) << endl; //Output : 4. 
    cout << findKthLargest(nums2, k2) << endl; //Output : 4.
    return 0; 
}
