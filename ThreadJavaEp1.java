public abstract class Interface implements Runnable {
	
	static Runnable tarefaRunnable = new Runnable() {
		
		public void run() {
			
			System.out.println("hello world");
			
		}
	};		
}

public abstract class ep1 extends Interface {

	public static void main(String[] args) {
				
		for (int i = 0; i < 10; i++) {
			
			Thread minhaThread = new Thread(tarefaRunnable);
		
			minhaThread.start();
			
		}
	}
}