///*
//���� ������
//�׸��� ��� �ȼ��� ����&�� ���ϰ�� �� �׸��� �������� b&w�� �ȴ�.
//��� �ȼ��� ���� ���� �ƴ϶�� �׸��� ���� ���� 2����Ͽ� �����Ѵ�. ���� ����� x(���� �� �κ��� ���� ���)(������ �� �κ��� ���� ���)
//
//�Է�
//ù�ٿ� �׽�Ʈ ���̽� C<=50�� �־����ϴ�. ���� C�ٿ� �ϳ��� ���� Ʈ���� ������ �׸��� �־����ϴ�.
//��� ���ڿ��� ���̴� 1,000 �����̸� ���� �׸��� ũ��� 2^20 * 2^20 �� ���� �ʽ��ϴ�.
//
//���
//�� �׽�Ʈ ���̽��� �� �ٿ� �־��� �׸��� ���Ϸ� ������ ����� ���� Ʈ�� �����ؼ� ����մϴ�.
//
//���� �Է�
//4
//w
//xbwwb
//xbwxwbbwb
//xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
//���� ���
//w
//xwbbw
//xxbwwbbbw
//xxwbxwwxbbwwbwbxwbwwxwwwxbbwb
//*/
//#include <iostream>
//
//using namespace std;
//
//char img[1001];
//int index;
//
//string Reverse()
//{
//    index++;
//    if (img[index] != 'x') return string(1, img[index]);
//
//    string upL = Reverse();
//    string upR = Reverse();
//    string dwL = Reverse();
//    string dwR = Reverse();
//
//    return string("x" + dwL + dwR + upL + upR);
//}
//
//int main(void)
//{
//    int C;
//    cin >> C;
//
//    for (int i = 0; i < C; i++) {
//        cin >> img;
//
//        index = -1;
//        cout << Reverse() << endl << endl;
//    }
//
//    return 0;
//}
