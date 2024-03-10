function adjustLights(lights) {
  const firstRedOrGreen = [0, 0]
  
   for(const [i, e] of lights.entries()) {
    const isRed = +(e == '🔴');
    const isGreen = 1 - isRed;

    firstRedOrGreen[0] += (i%2) * isRed + (1-i%2) * isGreen;
    firstRedOrGreen[1] += (i%2) * isGreen + (1-i%2) * isRed;
  }

  return Math.min(firstRedOrGreen[0], firstRedOrGreen[1]);
}

