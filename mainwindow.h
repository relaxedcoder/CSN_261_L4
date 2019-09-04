#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<iostream>
#include<fstream>
using namespace std;

struct Trie
{
    bool eow;
    Trie ** map;
    string meaning = "Invalid word";

    Trie()
    {
        map = new Trie*[1000];
    }

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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    Trie t;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void searchPressed();
};

#endif // MAINWINDOW_H
