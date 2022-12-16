#include <bits/stdc++.h>

using namespace std;
ostream& operator<<(ostream& stream, const vector<string>& vec)
{
    for(int i=0 ; i < vec.size() ; i++)
        stream << vec[i] <<'\n';
    return stream;
}


void ajouterMot(string mot)
{
    ofstream myFile;
    //open en mode append
    myFile.open("dictionary.txt",ofstream::app);
    myFile << mot << endl;
    myFile.close();
}


vector<string> SortingDictionary()
{
    //Sorting
    vector<string> sortedDict;
    ifstream newFile("dictionary.txt");
    string mot;
    while(getline(newFile,mot))
        sortedDict.push_back(mot);

    cout << "******************Avant sort*****************"<<endl;
    cout << sortedDict <<endl;

    sort(sortedDict.begin() , sortedDict.end());
    return sortedDict;
}
int main()
{
    ///**** Search in huge volume of data
    map<string,string> dict;
    string mot,description,mots;
    ifstream myFile("urbandict-word-defs.csv");
    getline(myFile,mots);
    while(getline(myFile,mots))
    {
        stringstream str(mots);
        getline(str,mot,',');
        getline(str,mot,',');//Le mot
        getline(str,description,',');
        getline(str,description,',');
        getline(str,description,',');
        getline(str,description,',');//Le description
        dict.insert(pair<string,string>(mot,description));

    }
    myFile.close();
    string searched ;
    int choix;
    while(true)
    {
        cout << "Entrez le mot : ";
        cin >> searched;
        auto search_itr = dict.find(searched);//search en map
        if (search_itr != dict.end())
            cout << search_itr->first << " : " << search_itr->second << '\n';
        else
            cout << searched<<" not found\n";
        do{
            cout <<"************************"<<endl;
            cout << "1:for continuer "<<endl;
            cout << "2:for sortir "<<endl;
            cout <<"************************"<<endl;
            cout << "entrez choix : ";
            cin >>choix;

        }while(choix!=2 && choix!=1);

        if(choix == 2) break;
    }

    /// **** sorting dictionary
    vector<string> sortedDict = SortingDictionary();
    cout << "******************Apres sort*****************"<<endl;
    cout << sortedDict;

    /// ***Ajouter mot au dictionaire
    cout << "Entrez mot a ajouter au dictionnaire : ";
    cin >> mot;
    ajouterMot(mot);




    return 0;
}
