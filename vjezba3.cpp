//#include <iostream>
//#include <cstddef>  
//#include <string>
//
//
//inline bool ascending(int a, int b) { return a < b; }
//inline bool descending(int a, int b) { return a > b; }
//
//void sortt(int arr[], std::size_t n, bool(*cmp)(int, int)) {
//	for (std::size_t i = 0; i < n - 1; ++i) {
//		for (std::size_t j = 0; j < n - i - 1; ++j) {
//			if (!cmp(arr[j], arr[j + 1])) {
//				std::swap(arr[j], arr[j + 1]);
//			}
//		}
//	}
//}
//
//
//template <typename T>
//void sortt_template(T arr[], std::size_t n, bool(*cmp)(T, T)) {
//	for (std::size_t i = 0; i < n - 1; ++i) {
//		for (std::size_t j = 0; j < n - i - 1; ++j) {
//			if (!cmp(arr[j], arr[j + 1])) {
//				std::swap(arr[j], arr[j + 1]);
//			}
//		}
//	}
//}
//
//
//
//auto is_even = [](int x) { return x % 2 == 0; };
//auto is_odd = [](int x) { return x % 2 != 0; };
//auto double_it = [](int x) { return 2 * x; };
//auto half_it = [](int x) { return x / 2; };
//
//void transform_parity(int arr[], std::size_t n) {
//	for (std::size_t i = 0; i < n; ++i) {
//		if (is_even(arr[i]))
//			arr[i] = half_it(arr[i]);
//		else
//			arr[i] = double_it(arr[i]);
//	}
//}
//
//void sum_and_product(const int arr[], std::size_t n, int &sum, int &product) {
//	sum = 0;
//	product = 1;
//	auto add_to_sum = [&](int x) { sum += x; };
//	auto multiply = [&](int x) { product *= x; };
//
//	for (std::size_t i = 0; i < n; ++i) {
//		add_to_sum(arr[i]);
//		multiply(arr[i]);
//	}
//}
//
//int sum_greater_than(const int arr[], std::size_t n, int prag) {
//	int s = 0;
//	auto add_if_greater = [prag, &s](int x) {
//		if (x > prag)
//			s += x;
//	};
//
//	for (std::size_t i = 0; i < n; ++i)
//		add_if_greater(arr[i]);
//
//	return s;
//}
//
//
//struct Student {
//	std::string ime;
//	std::string jmbag;
//	int godina;
//	int ects;
//	double prosjek;
//};
//
//void filter_students(
//	Student studenti[], std::size_t n,
//	void(*akcija)(Student &),
//	bool(*filter)(Student &))
//{
//	for (std::size_t i = 0; i < n; ++i) {
//		if (filter(studenti[i])) {
//			akcija(studenti[i]);
//		}
//	}
//}
//
//void print_student(Student &s) {
//	std::cout << s.ime << " (" << s.jmbag << "), godina: "
//		<< s.godina << ", ECTS: " << s.ects
//		<< ", prosjek: " << s.prosjek << '\n';
//}
//
//void promote_student(Student &s) {
//	s.godina++;
//}
//
//
//int main() {
//	int arr[] = { 5, 2, 9, 1, 7 };
//	std::size_t n = 5;
//
//	std::cout << "Originalni niz: ";
//	for (int x : arr) std::cout << x << " ";
//	std::cout << "\n";
//
//	sortt(arr, n, ascending);
//	std::cout << "Uzlazno sortirano: ";
//	for (int x : arr) std::cout << x << " ";
//	std::cout << "\n";
//
//	sortt(arr, n, descending);
//	std::cout << "Silazno sortirano: ";
//	for (int x : arr) std::cout << x << " ";
//	std::cout << "\n";
//
//	double arr_d[] = { 3.5, 1.2, 4.8 };
//	sortt_template(arr_d, 3, [](double a, double b) { return a < b; });
//	std::cout << "Sortirani double niz: ";
//	for (double x : arr_d) std::cout << x << " ";
//	std::cout << "\n";
//
//	int nums[] = { 2, 5, 8, 3 };
//	std::size_t m = 4;
//	transform_parity(nums, m);
//	std::cout << "Parni prepolovljeni, neparni udvostruceni: ";
//	for (int x : nums) std::cout << x << " ";
//	std::cout << "\n";
//
//	int sum, product;
//	sum_and_product(nums, m, sum, product);
//	std::cout << "Suma: " << sum << ", Produkt: " << product << "\n";
//
//	int prag = 5;
//	int suma_vecih = sum_greater_than(nums, m, prag);
//	std::cout << "Suma brojeva > " << prag << ": " << suma_vecih << "\n";
//
//	Student studenti[] = {
//		{"Ana", "001", 1, 30, 3.8},
//		{"Marko", "002", 1, 0, 2.9},
//		{"Iva", "003", 2, 50, 4.2},
//		{"Petar", "004", 3, 45, 3.6}
//	};
//	std::size_t br_stud = 4;
//
//	std::cout << "\n--- Studenti 1. godine s barem jednim polozenim ispitom ---\n";
//	filter_students(studenti, br_stud,
//		print_student,
//		[](Student &s) { return s.godina == 1 && s.ects > 0; });
//
//	std::cout << "\n--- Studenti s prosjekom > 3.5 ---\n";
//	filter_students(studenti, br_stud,
//		print_student,
//		[](Student &s) { return s.prosjek > 3.5; });
//
//	std::cout << "\n--- Povecanje godine studentima s >=45 ECTS ---\n";
//	filter_students(studenti, br_stud,
//		promote_student,
//		[](Student &s) { return s.ects >= 45; });
//
//	std::cout << "\n--- Studenti nakon promocije ---\n";
//	for (auto &s : studenti) print_student(s);
//
//	return 0;
//}