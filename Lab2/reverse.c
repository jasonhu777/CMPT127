
void reverse(int arr[], unsigned int len) {

	for (int i = 0, j = len-1; i < len/2; i++, j--) {
		int tmp = 0;
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;

	}
}