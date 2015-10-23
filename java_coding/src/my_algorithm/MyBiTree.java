package my_algorithm;

class Node {
	int data;
	Node lchild;
	Node rchild;

	public Node() {
		data = -1;
		lchild = rchild = null;
	}

	public Node(int data) {
		this.data = data;
		this.lchild = this.rchild = null;
	}
}

public class MyBiTree {

	Node root;

	public MyBiTree() {
		root = new Node();
	}

	public MyBiTree(int data) {
		root = new Node(data);
	}

//	思维错误，对这个树这个地方的理解错误造成在这个地方总是写错，注意：这种写法是错误的！！！！！！
//	public Node add(Node node, int data) {
//		Node curNode = new Node(data);
//		if (node.lchild == null)
//			node.lchild = curNode;
//		else if (node.lchild != null && node.rchild == null)
//			node.rchild = curNode;
//		else {
//			node.lchild = add(node.lchild, data);
//		}
//
//		return node;
//	}

	public Node add(Node node,int data)
	{
		if(root == null)
			root = new Node(data);
		else
		{
			if(data < node.data)
			{
				if(node.lchild == null)
					node.lchild = new Node(data);
				else
					node.lchild = add(node.lchild,data);
			}
			else
			{
				if(node.rchild == null)
					node.rchild = new Node(data);
				else
					node.rchild = add(node.rchild,data);
			}
		}
		return node;
	}
	
	public void insertLeft(Node node, int data) {
		Node lchild = new Node(data);
		node.lchild = lchild;
	}

	public void insertRight(Node node, int data) {
		Node rchild = new Node(data);
		node.rchild = rchild;
	}
	
	public void preTreavers(Node node)
	{
		if(node == null)
			return;
		else
		{
			System.out.println(node.data + " ");
			preTreavers(node.lchild);
			preTreavers(node.rchild);
		}
	}
	
	public static void main(String[] args)
	{
		MyBiTree biTree = new MyBiTree(0);
		biTree.add(biTree.root, 3);
		biTree.add(biTree.root, 5);
		biTree.add(biTree.root, 9);
		biTree.add(biTree.root, 12);
		biTree.add(biTree.root, 6);
		biTree.add(biTree.root, 2);
		biTree.preTreavers(biTree.root);
	}

}
