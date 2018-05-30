# PenktaUzduotis

## Įdomūs dalykai

Whitelist filtras
```cpp
	std::string filterLineWL(std::string & line){
		for (size_t i = 0; i < line.size(); i++){
			const char c = line.at(i);
			if((c < 65) || (c > 90 && c < 97) || (c > 122))
				replace(line.begin(), line.end(), c, ' ');
		}
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		return line;
	}
```

Blacklist filtras
```cpp
	std::string filterLineBL(std::string & line){
		const std::string filter = "0123456789/*-+.`~!@#$%^&*()_-=[]{}\\|\'\":;<>?,.";
		for (int i = 0; i < filter.size(); i++){
			replace(line.begin(), line.end(), filter.at(i), ' ');
		}
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		return line;
	}
```
