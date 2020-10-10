public abstract class Interface implements Runnable {
	
	static Runnable tarefaRunnable = new Runnable() {
		
		public void run() {
			
			System.out.println("hello world");
			
		}
	};		
}
