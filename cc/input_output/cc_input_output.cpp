// A sample cord of C++ input/output
// ref: http://purple-apple.hatenadiary.jp/entry/2017/02/05/202726

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <exception>

template<typename Num_type>
std::vector<std::vector<Num_type> >
Getdata(std::string filename, std::size_t ignore_line_num = 0){
    std::ifstream reading_file;
    reading_file.open(filename, std::ios::in);
    if(!reading_file)
        throw std::invalid_argument(filename + std::string("could not be opened."));
    
    std::string reading_line_buffer;
    
    //最初のignore_line_num行を空読みする
    for(std::size_t line = 0; line < ignore_line_num; line++){
        getline(reading_file,reading_line_buffer);
        if(reading_file.eof()) break;
    }
        
    Num_type num;
    char comma;

    std::vector<std::vector<Num_type> > data;
        
    while(std::getline(reading_file, reading_line_buffer)){    
        if(reading_line_buffer.size() == 0) break;
	std::vector<Num_type> temp_data;
	std::istringstream is(reading_line_buffer);
	while(is >> num){
	    temp_data.push_back(num);
	    is >> comma;
	}
	data.push_back(temp_data);
    }

    return data;
}

//動作テスト                                                                      
int main(){
    //読み込みデータ格納先2次元vectorを用意する、今回の数値型はなんでも良い
    std::vector<std::vector<double> > data;

    std::string filename("data/test.csv");
    
    //Getdata関数を使う    
    //テンプレート引数として読み込みデータの型名を指定(今回はdouble)。
    //第１引数に読み込みたいファイルのカレントディレクトリからのパスを指定する
    std::cout << "reading " << filename << "..." << std::endl;
    data = Getdata<double>(filename);

    for(std::size_t line=0 ;line < data.size() ;line++){
	for(int column=0 ;column < data[line].size() ;column++){
	    std::cout << data[line][column] << " ";
	}
	std::cout << std::endl;
    }
    std::cout << std::endl;

    //最初のn行を読み飛ばす場合には第２引数にnを入れる
    std::size_t n = 3;
    std::cout << "reading " << filename << "..." << std::endl;
    data = Getdata<double>(filename,n);

    for(std::size_t line=0 ;line < data.size() ;line++){
	for(std::size_t column=0 ;column < data[line].size() ;column++){
	    std::cout << data[line][column] << " ";
	}
	std::cout << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}