////피자의 20가지 토핑을 배열이 아닌 비트연산으로 집합연산 실시 실습
//
//#include <iostream>
//
//using namespace std;
//
//int main() {
//	int emptypizza = 0;
//	int fullpizza = (1 << 20) - 1;
//	int topping = 0;
//	
//	int num;
//	while (1) {
//		cout << "1. : 토핑1\n"
//			<< "2. : 토핑2\n"
//			<< "3. : 토핑3\n"
//			<< "4. : 토핑4\n"
//			<< "5. : 토핑5\n"
//			<< "6. : 토핑6\n"
//			<< "7. : 토핑7\n"
//			<< "8. : 토핑8\n"
//			<< "9. : 토핑9\n"
//			<< "10. : 토핑10\n"
//			<< "11. : 토핑11\n"
//			<< "12. : 토핑12\n"
//			<< "13. : 토핑13\n"
//			<< "14. : 토핑14\n"
//			<< "15. : 토핑15\n"
//			<< "16. : 토핑16\n"
//			<< "17. : 토핑17\n"
//			<< "18. : 토핑18\n"
//			<< "19. : 토핑19\n"
//			<< "20. : 토핑20\n"
//			<< "21. : 토핑 제거\n"
//			<< "그 외. : 종료\n";
//		cin >> num;
//
//		if (0 >= num || num > 21) break;	//범위 외
//		
//		if (num == 21) {
//			system("cls");
//			while (1) {
//				cout << "제거할 토핑\n"
//					<< "1. : 토핑1\n"
//					<< "2. : 토핑2\n"
//					<< "3. : 토핑3\n"
//					<< "4. : 토핑4\n"
//					<< "5. : 토핑5\n"
//					<< "6. : 토핑6\n"
//					<< "7. : 토핑7\n"
//					<< "8. : 토핑8\n"
//					<< "9. : 토핑9\n"
//					<< "10. : 토핑10\n"
//					<< "11. : 토핑11\n"
//					<< "12. : 토핑12\n"
//					<< "13. : 토핑13\n"
//					<< "14. : 토핑14\n"
//					<< "15. : 토핑15\n"
//					<< "16. : 토핑16\n"
//					<< "17. : 토핑17\n"
//					<< "18. : 토핑18\n"
//					<< "19. : 토핑19\n"
//					<< "20. : 토핑20\n"
//					<< "그 외. : 종료\n";
//
//
//				//topping -= (1 << (num - 1));	//num - 1 번째 비트를 뺀다 == 토핑이 없을때는 오류발생 (0100 - 0010 = 0010)
//				topping &= ~(1 << (num - 1));	//반전시켜서 AND 연산 (0100 & {~(0010)} = 0100 & 1101 = 0100), (0110 & {~(0010)} = 0110 & 1101 = 0100)
//
//
//				if (0 >= num || num > 20) break;	//범위 외
//
//			}
//			system("cls");
//			continue;	//while문 종료 후 비트 연산 결과에 영향을 주지 않도록
//		}
//
//		topping |= (1 << (num - 1));	//num - 1 번째 비트와 OR 연산
//
//		system("cls");
//	}
//
//	//토핑 여부 확인
//	for (int i = 0; i < 20; i++) {
//		cout << "토핑" << i + 1;
//
//		if (topping & (1 << (i + 1))) cout << " ○\n";
//		else cout << " X\n";
//	}
//
//	return 0;
//}