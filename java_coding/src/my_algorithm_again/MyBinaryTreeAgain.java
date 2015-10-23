package my_algorithm_again;

class Node {
	int data;
	Node lchild;
	Node rchild;

	public Node(int data) {
		this.data = data;
		this.lchild = null;
		this.rchild = null;
	}
}

public class MyBinaryTreeAgain {


	public static Node insert(Node node, int data) {
		Node cur = new Node(data);
		if (node == null)
			node = cur;
		else {
			if (node.data > data && node.lchild == null)
				node.lchild = cur;
			else if (node.data > data && node.lchild != null)
				node.lchild = insert(node.lchild, data);
			else if (node.data <= data && node.rchild == null)
				node.rchild = cur;
			else
				node.rchild = insert(node.rchild, data);
		}
		return node;
	}
	
	public static void minTreaver(Node node)
	{
		if(node == null)
			return ;
		else
		{
			minTreaver(node.lchild);
			System.out.print(node.data + " ");
			minTreaver(node.rchild);
		}
	}
	
	public static int height(Node node)
	{
		if(node == null)
			return -1;
		else
			return (Math.max(height(node.lchild), height(node.rchild))+1);
	}
	
	public static void main(String[] args)
	{
		int[] a = new int[]{3,1,6,7,9,2,11,10,33,21,44};
		Node root = new Node(8);
		for(int i = 0 ; i < a.length ; i ++)
			root = insert(root,a[i]);
		minTreaver(root);
		System.out.println("\n" + height(root));
	}
	
}
