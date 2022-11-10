#include<iostream>
using namespace std;

int a[101], sorted[101];

void merge(int left, int right) {
	int mid;
	int p1, p2, p3;

	if (left < right) {
		mid = (left + right) / 2;
		merge(left, mid);
		merge(mid + 1, right);
		p1 = left; // ���ĵ� ���� �迭�� ���� �ε���
		p2 = mid + 1; // ���ĵ� ������ ����Ʈ�� ���� �ε���
		p3 = left; // �պ��� ����Ʈ�� ���� �ε���
		//�������ĵ� �迭�� �պ�
		while (p1 <= mid && p2 <= right) {
			if (a[p1] < a[p2]) sorted[p3++] = a[p1++];
			else sorted[p3++] = a[p2++];
		}
		// ���� �ִ� ���� �迭 �ϰ� ����
		while (p1 <= mid) sorted[p3++] = a[p1++];

		// ���� �ִ� ������ �迭 �ϰ� ����
		while (p2 <= right) sorted[p3++] = a[p2++];
		
		//�迭 sorted�� �迭 a�� �纹��
		for (int i = left; i <= right; i++) {
			a[i] = sorted[i];
		}
	}
}

int main() {
	int n, i;
	cin >> n; 
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}
	merge(1, n);
	for (i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}