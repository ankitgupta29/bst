#include<iostream>
#include<string.h>

using namespace std;

int dictionaryContains(string word)
{
        string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                                       "icecream","and","go","i","like","ice","cream"};
            int size = sizeof(dictionary)/sizeof(dictionary[0]);
                for (int i = 0; i < size; i++)
                            if (dictionary[i].compare(word) == 0)
                                           return true;
                    return false;
}

static int count = 0;
bool find_sentence(string str)
{
    cout << str << endl;
    int i;
    int size = str.size();
    if (size == 0)
        return true;

    for (i = 1; i <= size; i++)
        if(dictionaryContains(str.substr(0,i))&& find_sentence(str.substr(i, size-i)))
        {
            cout << "true\n";
            count++;
            return true;
        }

    return false;
}

bool find_sentence_dp(string str)
{

    cout << str << endl;
    int i;
    int size = str.size();
    bool *word =  new bool[size+1]();
    for (i = 0; i <= size; i++)
           word[i] = false;

    for(i = 1; i <= size; i++)
    {

        if (dictionaryContains(str.substr(0, i)) && word[i] == false){
            word[i] = true;
            cout << str.substr(0,i) << endl;
        }

        if (word[i] == true) {
                for (int j =i +1; j <=size; j++)
                {
                        if (dictionaryContains(str.substr(i, j - i)) && (word[j] == false)) {
                            word[j] = true;
                            count++;
                        }
                        if (j == size && word[j] == true)
                        {
                            cout << str.substr(0,i) << "  " << str.substr(i, j -i) << endl;
                            return true;
                        }
                }

        }
    }
        return false;
}

int main()
{
        std:string str = "ilikeicecream";
        int val = find_sentence_dp(str);
        cout << "output: " << val <<  "  count :"<< count << endl;
}
