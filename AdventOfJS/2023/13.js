function calculateTime(deliveries) {
  const maxSeconds = 25200;

  let total = 0;

  for (const duration of deliveries) {
    const hms = duration.split(":");

    total += +hms[0] * 3600 + +hms[1] * 60 + +hms[2];
  }

  const need = Math.abs(maxSeconds - total);

  const h = (need/3600 | 0).toString().padStart(2, "0");
  const m = ((need%3600)/60 | 0).toString().padStart(2, "0") ;
  const s = ((need%3600)%60).toString().padStart(2, "0");

  const ans = `${h}:${m}:${s}`;

  return ["", "-"][+(maxSeconds - total > 0)] + ans;
}
