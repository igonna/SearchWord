#include <iostream>
#include <sstream>
#include <fstream>
std::string getStringFromFile(std::string fileName)
{
        std::ifstream ifile(fileName);
        std::string strDataFromFile;
        if(ifile)
        {
                std::ostringstream ss;
                ss << ifile.rdbuf();
                strDataFromFile = ss.str();
        }
        ifile.close();
        return strDataFromFile;
}

void searchWord(std::string words, std::string word, char stopChar)
{
	unsigned int wordSize = word.size();
	unsigned int pos = 0;
	unsigned int isEqual = 0;
	bool isWord = false;
	for(unsigned int step = 0; step < words.size(); ++step)
	{
		if(words[step] == word[isEqual])
		{
			++isEqual;
			if(isEqual == wordSize)
			{
				pos = step - wordSize + 1;
				isWord = true;
				break;
			}
		}
		else
		{
			isEqual = 0;
		}
	}
	if(isWord)
	{
		unsigned int step = pos;
		do
		{
			std::cout << words[step];
			++step;
		}
		while(words[step] != stopChar);
		std::cout << std::endl;
	}
	else
		std::cout << "no word!" << std::endl;
}
int main(int argc, char** argv)
{
	if(argc < 4)
        {
		if(argc > 1)
		{
			if(argv[1] == std::string("--help"))
        		{
                		std::cout << "./SearchWord.out [file name] [word for search] [stop character]" << std::endl;
        		}

		}
		else
		{
                	std::cout << "few args" << std::endl;
                	std::cout << "./SearchWord.out --help" << std::endl;
		}
		return 0;
        }
	std::string words = getStringFromFile(argv[1]);
	std::string word(argv[2]);
	char stopChar = '\n';
	searchWord(words, word, stopChar);
	return 0;
}
