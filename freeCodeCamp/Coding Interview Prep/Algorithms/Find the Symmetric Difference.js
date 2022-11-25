function sym(...args) {
  let result = new Set();
  
  for (let s of args) {
    let set1 = new Set(s)
    let set2 = result;
    let set3 = new Set();

    for (let element of set1) {
      if (!set2.has(element))
        set3.add(element);
    }

    for (let element of set2) {
      if (!set1.has(element))
        set3.add(element);
    }

    result = set3;
  }

  return Array.from(result);
}

console.log(sym([1, 2, 3], [5, 2, 1, 4]));