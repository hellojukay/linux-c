package main

import (
	"flag"
	"log"
	"net/http"
	"os"
	"sync"
)

var u string
var thread int

func init() {
	flag.StringVar(&u, "url", "", "http[s] link url")
	flag.Parse()
}

type fileInfo struct {
	size     int64
	filename string
}
type Range struct {
	Start int
	End   int
}

type Downloader struct {
	Url  string
	File string
	fh   *os.File
	wg   sync.WaitGroup
}

// 下载文件，等待所有 goroutine 返回
func (loader *Downloader) Down(thread int) error {
	info, err := getFileInfo(loader.Url)
	if err != nil {
		return err
	}
	fh, err := os.OpenFile(info.filename, os.O_CREATE|os.O_RDWR, 0644)
	if err != nil {
		if err != nil {
			return err
		}
	}
	loader.fh = fh
	ranges, err := loader.getRange()
	if err != nil {
		return err
	}
	for _, r := range ranges {
		// 为每一个 goroutine 分配任务
		func() {
			defer loader.wg.Add(1)
			go loader.down(r)
		}()
	}
	loader.wg.Wait()
	return nil
}

// 下载分片
func (loader *Downloader) down(r Range) error {
	defer loader.wg.Add(-1)
	return nil
}

// 获取分配下载区间
func (loader *Downloader) getRange() ([]Range, error) {
	// 链接服务器，获取文件大小
	res, err := http.Get(loader.Url)
	if err != nil {
		return nil, err
	}
	defer res.Body.Close()
	log.Printf("content length %d", res.ContentLength)

	return nil, nil
}

func getFileInfo(url string) (*fileInfo, error) {
	return &fileInfo{
		size:     0,
		filename: "a.txt",
	}, nil

}

func main() {
	log.Printf("start downloading...\n")
	var loader = &Downloader{
		Url:  u,
		File: "",
	}
	err := loader.Down(thread)
	if err != nil {
		log.Printf("download from %s failed,%s\n", u, err)
		os.Exit(1)
	}
}
