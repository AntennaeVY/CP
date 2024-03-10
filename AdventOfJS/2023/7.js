function drawGift(size, symbol) {
  if (size == 1)
    return "#\n";

  let ans = " ".repeat(size-1) + "#".repeat(size) + "\n";

  for(let i=size-2; i > 0; i--) {
    ans += " ".repeat(i) + "#" + symbol.repeat(size-2) + "#";
    ans += symbol.repeat(size-i-2) + "#\n";
  }
  ans += "#".repeat(size) + symbol.repeat(size-2) + "#\n";

  for(let i=0; i < size-2; i++) {
    ans += "#" + symbol.repeat(size-2) + "#";
    ans += symbol.repeat(size-i-3) + "#\n";
  }

  ans += "#".repeat(size) + '\n';

  return ans;
}
