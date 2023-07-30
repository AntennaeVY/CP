function selectSleigh(distance, sleighs) {
  sleighs = sleighs.filter((s) => s.consumption * distance <= 20)
  sleighs.unshift({ name: null })
  return sleighs.at(-1).name
}
