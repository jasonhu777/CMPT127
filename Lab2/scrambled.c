
int scrambled(unsigned int a[], unsigned int b[], unsigned int len) {
	int arr[100] = {  };
	if (len == 0) {
		return 1;
	}
	
	for (int i = 0; i < len; i++) {
		int tmp1 = 0, tmp2 = 0;
		tmp1 = a[i];
		tmp2 = b[i];
		arr[tmp1]++;
		arr[tmp2]--;
	}
	for (int i = 0; i < 100; i++) {
		if (arr[i] != 0) {
			return 0;
		}
	}
	return 1;
}