#include<iostream>
#include<fstream>
using namespace std;

/** This is the structure for Trie Data Structure.
*/
struct Trie
{
	bool eow;
	Trie ** map;
	string meaning = "Invalid word";
	
	Trie()
	{
		map = new Trie*[1000];
	}
	
	/** This function inserts the word and meaning in Trie
	* @param word The string word
	* @param meaning The meaning of word
	*/	
	void insert(string word,string means)
	{
		Trie * temp = this;
		for(int i=0;i<word.size();i++)
		{
			if(temp->map[word[i]]==NULL)
			{
				temp->map[word[i]] = new Trie;
			}
			temp = temp->map[word[i]];
		}
		temp->eow = 1;
		temp->meaning = means;
	}
	
	/** This function gets the meaning of given word
	* @param word The string word
	*/
	string getmeaning(string word)
	{
		Trie * temp = this;
		for(int i=0;i<word.size();i++)
		{
			if(temp->map[word[i]]==NULL)
			{
				return "Invalid word";
			}
			temp = temp->map[word[i]];
		}
		return temp->meaning;
	}
	
	/** This function loads the Trie from given file
	* @param file The file path in form of string
	*/
	void inputfromfile(string file)
	{
		ifstream fin;
		fin.open(file,ios::in);
		while(fin)
		{
			char c='d';
			string word = "";
			string meaning = "";
			fin>>c;
			while(c!=',')
			{
				word += c;
				fin>>c;
			}
			fin>>c;
			fin>>c;
			while(c!='\"')
			{
				meaning += c;
				fin>>std::noskipws>>c;
			}
			fin>>c;
			insert(word,meaning);
		}	
		fin.close();
	}
};

int main()
{
	Trie t;
	t.inputfromfile("L4_P1_input.csv");
	cout<<t.getmeaning("BOTCH");
	return 0;
}
