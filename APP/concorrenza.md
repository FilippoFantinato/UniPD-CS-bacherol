

# Concorrenza

## Thread

```java
/**
* Allocates a new Thread object so that it has target as
* its run object, has the specified name as its name, and
* belongs to the thread group referred to by group, and
* has the specified stack size.
*
*/
public Thread(ThreadGroup group,
Runnable target,
String name,
long stackSize);

/**
* Causes this thread to begin execution; the Java Virtual
* Machine calls the run method of this thread.
*/
void start();

/**
* Causes the currently executing thread to sleep
* (temporarily cease execution) for the specified number of
* milliseconds, subject to the precision and accuracy of
* system timers and schedulers
*
* @param millis the length of time to sleep in milliseconds
*
*/
public static void sleep(long millis)
throws InterruptedException

/**
* The Runnable interface should be implemented by any
* class whose instances are intended to be executed
* by a thread.
*/
@FunctionalInterface
public interface Runnable 
{
    /**
    * The general contract of the method run is that
    * it may take any action whatsoever.
    */
	void run();
}

/**
* Returns this thread's name.
*/
public String getName();

/**
* Tests if this thread is alive.
*/
public boolean isAlive();

/**
* Returns a reference to the currently executing thread
* object.
*
*/
public static Thread currentThread();

/**
* Interrupts this thread.
*
*/
public void interrupt();

/**
* Set the handler invoked when this thread abruptly
* terminates due to an uncaught exception.
*/
public void setUncaughtExceptionHandler(Thread.UncaughtExceptionHandler eh);
```

## Executor

```java
/**
* Executes the given command at some time in the future.
* The command may execute in a new thread, in a pooled
* thread, or in the calling thread, at the discretion
* of the Executor implementation.
*
* @param command the runnable task
*
*/
void execute(Runnable command);
```

| Tipo                     | Funzionamento                                        |
| ------------------------ | ---------------------------------------------------- |
| **CachedThreadPool**     | Riusa thread già creati, ne crea nuovi se necessario |
| **FixedThreadPool**      | Riusa un insieme di thread di dimensione fissa       |
| **ScheduledThreadPool**  | Esegue i compiti con una temporizzazione             |
| **SingleThreadExecutor** | Usa un solo thread per tutti                         |

## Callables

```java
/**
* A task that returns a result and may throw an exception.
*/
@FunctionalInterface
public interface Callable < V >
{
    /**
    * Computes a result, or throws an exception if unable
    * to do so.
    *
    * @return computed result
    * @throws Exception - if unable to compute a result
    */
    V call() throws Exception;
}

/**
* An Executor that provides methods to manage termination
* and methods that can produce a Future for tracking
* progress of one or more asynchronous tasks.
*
*/
public interface ExecutorService extends Executor;

/**
* Submits a value-returning task for execution and
* returns a Future representing the pending results
* of the task.
*
* @param T - the type of the task's result
* @param task - the task to submit
* @return a Future representing pending completion
* of the task
*
*/
<T> Future<T> submit(Callable<T> task);

/**
* A Future represents the result of an asynchronous
* computation. Methods are provided to check if the
* computation is complete, to wait for its completion,
* and to retrieve the result of the computation.
*
*/
public interface Future< V >;

/**
* Waits if necessary for the computation to complete,
* and then retrieves its result.
*
*/
T get();

/**
* Returns true if this task completed.
*
*/
boolean isDone();
```

## ExecutorService

```java
/**
* Executes the given tasks, returning the
* result of one that has completed successfully
* (i.e. without throwing an exception), if any do.
*
*/
< T > T invokeAny(Collection < ? extends Callable< T > > tasks);

/**
* Executes the given tasks, returning a list of Futures
* holding their status and results when all complete.
* Future.isDone() is true for each element of the
* returned list.
*/
< T > List< Future< T > > invokeAll(Collection< ? extends Callable< T > > tasks);

/**
* Initiates an orderly shutdown in which previously
* submitted tasks are executed, but no new tasks will
* be accepted.
*
*/
void shutdown();

/**
* Blocks until all tasks have completed execution after a
* shutdown request, or the timeout occurs, or the current
* thread is interrupted, whichever happens first.
*
*/
boolean awaitTermination(long timeout, TimeUnit unit);

/**
* Returns true if all tasks have completed following
* shut down.
*
*/
boolean isTerminated();

/**
* Attempts to stop all actively executing tasks, halts
* the processing of waiting tasks, and returns a list
* of the tasks that were awaiting execution.
*
*/
List< Runnable > shutdownNow()
```

