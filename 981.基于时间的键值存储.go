/**
 * Your TimeMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Set(key,value,timestamp);
 * param_2 := obj.Get(key,timestamp);
 */

type pair struct {
	t int
	v string
}

// hash map & sort
type TimeMap struct {
	m map[string][] pair
}


func Constructor() TimeMap {
	return TimeMap{map[string][]pair{} }
}

func (m *TimeMap) Set(key string, value string, timestamp int)  {
	m.m[key] = append(m.m[key], pair{timestamp, value})
}


func (m *TimeMap) Get(key string, timestamp int) string {
	p := m.m[key]
	i := sort.Search(len(p), func(i int) bool {
		return p[i].t > timestamp
	})
	if i > 0 {
		return p[i - 1].v
	}
	return ""
}