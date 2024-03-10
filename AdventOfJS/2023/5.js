function cyberReindeer(road, time) {
  const ans = [];
  const maxTime = 5;
  
  let now = 0;
  let current = road.split("");
  let pos = road.indexOf("S");
  let prev = '.';

  ans.push(current.join(""));

  while(++now < time) {
    if (now == maxTime) {
      current = current
                .join("")
                .replaceAll("|", "*")
                .split("");
    }

    if (pos < current.length && current[pos+1] != "|") {
      current[pos] = prev;
      prev = current[pos+1];
      current[pos+1] = 'S';

      pos++;
    }

    ans.push(current.join(""));
  }

  return ans;
}
