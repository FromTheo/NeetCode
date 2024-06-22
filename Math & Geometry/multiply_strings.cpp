#include <iostream>
#include <vector>
#include <string>

using namespace std; 

/* -------- Subject --------  
You are given two strings num1 and num2 that represent non-negative integers.
Return the product of num1 and num2 in the form of a string.
Assume that neither num1 nor num2 contain any leading zero, unless they are the number 0 itself. */

/* -------- Explanation --------
Traitons le cas où l'un des deux est 0 : on renvoie 0. 
Ensuite, créeons un vecteur `num` visant à contenir les résultats du produit, il est inialisé avec une taille de nums1.size() + nums2.size(), soit
la taille maximale de chiffres. 
Maintenant, faisons le produit en commencant par le chiffre des unités (en les convertissant pour ne pas travailler avec leurs représentations ASCII).
Gérons le principe des retenues, avec /10 et %10. 
Plus qu'a ignorer les zéros à gauche et ensuite de convertir en string (cette fois avec + '0'). 
Bien entendu, mais ce n'était pas le but ici, on aurait pu utiliser stoi() et to_string(). */

string multiply(string num1, string num2) 
{
    if (num1 == "0" || num2 == "0") return "0";
        
    vector<int> num(num1.size() + num2.size(), 0);
    
    for (int i = num1.size() - 1; i >= 0; --i) 
    {
        for (int j = num2.size() - 1; j >= 0; --j) 
        {
            num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            num[i + j] += num[i + j + 1] / 10;
            num[i + j + 1] %= 10;
        }
    }
    
    int i = 0;
    while (i < num.size() && num[i] == 0) ++i;

    string res = "";
    while (i < num.size()) res.push_back(num[i++] + '0');
        
    return res;
}

int main()
{
    string num1 = "3", num2 = "4";      //Output : 12
    cout << multiply(num1, num2) << endl; 
    string num3 = "111", num4 = "222";  //Output : 24642
    cout << multiply(num3, num4) << endl; 
    return 0; 
}