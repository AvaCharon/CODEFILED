public class see{
    public static void main(String[] args) {
		ThreadGroup threadGroup = Thread.currentThread().getThreadGroup();
		//activeCount()返回当前正在活动的线程的数量
		int total = Thread.activeCount();
		Thread[] threads = new Thread[total];
		//enumerate(threads)将当前线程组中的active线程全部复制到传入的线程数组threads中
		// 并且返回数组中元素个数，即线程组中active线程数量
		threadGroup.enumerate(threads);
		for (Thread t:threads){
			System.out.println("线程"+t.getId()+" "+t.getName());
		}
	}

}
