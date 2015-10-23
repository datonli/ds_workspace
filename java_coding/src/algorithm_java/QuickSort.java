package algorithm_java;

public class QuickSort {
	public static void main(String[] args) {
		int[] iArgs = new int[] { 72, 6, 57, 88, 60, 42, 83, 73, 48, 85 };
		int iLength = 5, left = 0, right = iArgs.length - 1;
		QuickSort quickSort = new QuickSort();
		quickSort.recursive(iArgs, left, right);
		for (int i = 0; i < iArgs.length; i++) {
			System.out.print(iArgs[i] + " ");
		}
	}

	private void recursive(int[] args, int left, int right) {
		if (left < right) {
			int iIndex = qucikSort(args, left, right); // iIndex 是基数放在数据位置
			recursive(args, left, iIndex - 1); // 为什么left不能从0
			recursive(args, iIndex + 1, right);// 为什么 right不等于length
		}
	}

	private int qucikSort(int[] args, int left, int right) {
		int iBase = args[left];
		while (left < right) {
			while (left < right && args[right] >= iBase) {
				right--;
			}
			args[left] = args[right];
			while (left < right && args[left] <= iBase) {
				left++;
			}
			args[right] = args[left];
		}
		args[left] = iBase;
		return left;
	}
}
