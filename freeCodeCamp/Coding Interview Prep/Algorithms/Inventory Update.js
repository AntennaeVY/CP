function updateInventory(arr1, arr2) {
    const map = new Map(arr1.map(([qty, str]) => [str, qty]));
    
    for (let [qty, str] of arr2) {
        map.set(str, (map.get(str) ?? 0) + qty);
    }

    const result = Array.from(map).map(([str, qty]) => [qty, str]);

    return result.sort((a,b) => a[1].localeCompare(b[1]));
}

// Example inventory lists
var curInv = [
    [21, "Bowling Ball"],
    [2, "Dirty Sock"],
    [1, "Hair Pin"],
    [5, "Microphone"]
];

var newInv = [
    [2, "Hair Pin"],
    [3, "Half-Eaten Apple"],
    [67, "Bowling Ball"],
    [7, "Toothpaste"]
];

updateInventory(curInv, newInv);