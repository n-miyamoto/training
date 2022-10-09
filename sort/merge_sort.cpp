#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n;

void create_data(vector<int> &data){

	std::random_device seed_gen;
	std::mt19937 engine(seed_gen());
	std::uniform_real_distribution<> dist1(-10000, 10000);

	const int n = data.size();
	for(auto &x : data){
		x = (int)dist1(engine);
	}
}

void show_data(const vector<int> &data){
	for(auto &x : data){
		std::cout << x << ", ";
	}
	std::cout << std::endl;
}

void copy_data(const vector<int> &src, vector<int> &dst){
	for(int i=0;i<src.size();i++){
		dst[i] = src[i];
	}
}

void bubble_sort(vector<int> &input){
	const int n = input.size();
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(input[j] > input[j+1]){
				int tmp = input[j];
				input[j] = input[j+1];
				input[j+1] = tmp;
			}
		}
	}
}

void sort(vector<int> &input_data, vector<int> &output_data, const int begin, const int end){

	const int data_num = end-begin;
	if(data_num <=1){
		return ;
	}

	const int split_index = (begin + end + 1)/2;

	sort(input_data, output_data, begin, split_index);
	sort(input_data, output_data, split_index, end);


	int k = begin;
	int l = split_index;
	for(int i=begin;i<end;i++){
		if(k==split_index){
			output_data[i] = input_data[l];
			l++;
		}else if(l==end){
			output_data[i] = input_data[k];
			k++;
		}else if(input_data[k] < input_data[l]){
			output_data[i] = input_data[k];
			k++;
		}else{
			output_data[i] = input_data[l];
			l++;
		}
	}

	for(int i=begin;i<end;i++){
		input_data[i] = output_data[i];
	}
}

int main(void){
	cin >> n;

	vector<int> original_data(n);
	vector<int> input_data1(n);
	vector<int> input_data2(n);
	vector<int> output_data(n);

	create_data(original_data);
	std::cout << "show data \r\n";
	show_data(original_data);

	copy_data(original_data, input_data1);
	copy_data(original_data, input_data2);

	std::chrono::system_clock::time_point  start, end;
    std::time_t time_stamp;

    start = std::chrono::system_clock::now(); 
	sort(input_data1, output_data, 0, n);
	end = std::chrono::system_clock::now();

	auto time1 = end - start;

    start = std::chrono::system_clock::now(); 
	bubble_sort(input_data2);
	end = std::chrono::system_clock::now();

	auto time2 = end - start;

	//data validation. compare with bubble sort.
	for(int i=0;i<input_data1.size();i++){
		if(input_data1[i] != input_data2[i]){
			std::cout << "!!!!!ERROR mismatch!!!!!!\r\n";
		}
	}

	auto msec1 = std::chrono::duration_cast<std::chrono::milliseconds>(time1).count();
	auto msec2 = std::chrono::duration_cast<std::chrono::milliseconds>(time2).count();
    std::cout << msec1 << " msec" << std::endl;
    std::cout << msec2 << " msec" << std::endl;
 
	return 0;
}
