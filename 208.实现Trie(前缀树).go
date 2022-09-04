/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */

type Trie struct {
	is_end bool
	next [26]*Trie
}


func Constructor() Trie {
	return Trie{}
}


func (this *Trie) Insert(word string)  {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.next[c] == nil {
			node.next[c] = &Trie()
		}
		node = node.next[c]
	}
	node.is_end = true
}


func (this *Trie) searchPrefix(word string) *Trie {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.next[c] == nil {
			return nil
		}
		node = node.next[c]
	}
	return node
}


func (this *Trie) Search(word string) bool {
	node := searchPrefix(word)
	return node != nil && node.is_end
}


func (this *Trie) StartsWith(prefix string) bool {
	return this.searchPrefix(prefix) != nil
}

