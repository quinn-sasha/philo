# 課題要件

- 哲学者の数：1一人以上
- 哲学者の行動：
    - 食べる、考える、寝る
    - 一つの動作をしているときは、他の行動はできない
    - 行動パターン: 食べ終わったら、寝て、起きたら考え始める
- フォークの数：哲学者と同じ数
- 食べるためには、右と左のフォークを両方掴む必要がある
- 哲学者は食べれないと、餓死する　(もし哲学者が一人しかいなければフォークは一つしかない（つまり食べれない))
- 禁止事項
    - 哲学者どうして意思疎通を取ってはいけない
    - 哲学者は餓死してはいけない

### プログラムへの引数

- number_of_philosophers: 哲学者の人数、およびフォークの総数
- time_to_die（ミリ秒単位）: 最後の食事開始時点またはシミュレーション開始から time_to_die ミリ秒以内に食事を開始しなかった哲学者は死亡します。
- time_to_eat（ミリ秒単位）: 哲学者が食事を完了するのに必要な時間。この期間中はフォークを2本保持している必要があります。
- time_to_sleep（ミリ秒単位）: 哲学者が睡眠に費やす時間
- number_of_times_each_philosopher_must_eat（任意の引数）: すべての哲学者が少なくとも number_of_times_each_philosopher_must_eat 回食事を終えた場合、シミュレーションは終了します。

### ログ

以下のような形式でログを残す

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

- 表示されたメッセージは他のメッセージと重ならないようにする
- 哲学者の死を告知するメッセージは、実際の死亡から 10ms 以内に表示されなければならない

### プログラムの要件

- **複数のスレッドが同じメモリ領域に同時にアクセスしては行けない (各フォークを mutex で保護する必要がある）**
- 各哲学者はスレッドとして表現される
- 使用可能外部関数：
    - 注意：exit 使えない

```
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
```
