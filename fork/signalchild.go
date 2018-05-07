package main

import(
	"os"
	"syscall"
	"fmt"
	"time"
)

// 一个进程死亡以后，系统会像这个进程的父进程发送signalchild信号，我们这里可以测试一下
// 这里测试并没有收到信号
func main(){
	var c = make(chan os.Signal)
	go func(){
		var s = <-c
		fmt.Printf("singal=%s\n",s.String())
	}()
	var env []string
	env = append(env,"child=true")
	exeAttr := &syscall.ProcAttr{
		Env:env,
		Files:[]uintptr{os.Stdin.Fd(),os.Stdout.Fd(),os.Stderr.Fd()},
	}
	// 如果是子进程，就不在执行fork了,这里进程死亡s
	if os.Getenv("child") != "" {
		return
	}
	fmt.Printf("parent pid = %d\n",os.Getpid())
	pid , err := syscall.ForkExec(os.Args[0],os.Args,exeAttr)
	if err != nil{
		panic(err)
	}
	if pid > 0{
		fmt.Printf("child pid=%d\n",pid)
		time.Sleep(10*time.Second)
	}
}