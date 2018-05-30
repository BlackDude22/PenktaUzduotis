#ifndef WORDMAP_H
#define WORDMAP_H

#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <iomanip>
#include <algorithm>

class word_map{
public:
	typedef std::pair<size_t, std::set<unsigned int>> value_pair;
	typedef std::pair<std::string, value_pair> word_pair;
private:
	std::map<std::string, value_pair> word_map_;
	size_t word_length = 0;
	size_t frequency_length = 0;
public:
	void addWord(std::string word, unsigned int line = 0){
		if (!word.empty()){
			std::set<unsigned int> someset;
			auto result = word_map_.insert(word_pair(word, value_pair(1, someset)));
			if (result.second == false)
				result.first->second.first++;
			result.first->second.second.insert(line);
			word_length = std::max(word_length, word.size());
			frequency_length = std::max(frequency_length, std::to_string(result.first->second.first).length());
		}
	}

	void printMap(unsigned int minimum = 1){
		for (const auto &pair : word_map_)
			if (pair.second.first >= minimum) {
        		std::cout << std::fixed << std::setw(word_length) << pair.first << ' ' << std::fixed << std::setw(frequency_length) << pair.second.first << ' ';
        		for (auto it = pair.second.second.begin(); it != pair.second.second.end(); it++)
        			std::cout << *it << ' ';
        		std::cout << std::endl;
			}

	}

	template<typename stream_type>
	void readFromStream(stream_type& input_stream){
		std::string line;
		unsigned int i = 1;
		while (getline(input_stream, line)){
			filterLine(line);
			std::istringstream ss(line);
            std::string word;
            while(ss >> word)
				addWord(word, i);
			i++;
		}
	}

	size_t getCount(std::string key){
		auto search = word_map_.find(key);
		return search->second.first;
	}

	std::set<unsigned int> getSet(std::string key){
		auto search = word_map_.find(key);
		return search->second.second;
	}

private:
	std::string filterLine(std::string & line){
		for (size_t i = 0; i < line.size(); i++){
			const char c = line.at(i);
			if((c < 65) || (c > 90 && c < 97) || (c > 122))
				replace(line.begin(), line.end(), c, ' ');
		}
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		return line;
	}

	// std::string filterLine(std::string line){
	// 	// setlocale(LC_ALL, "Lithuanian");
	// 	const std::string filter = "0123456789/*-+.`~!@#$%^&*()_-=[]{}\\|\'\":;<>?,.";
	// 	for (int i = 0; i < filter.size(); i++){
	// 		replace(line.begin(), line.end(), filter.at(i), ' ');
	// 	}
	// 	return line;
	// }
};

#endif