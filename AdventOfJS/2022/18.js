function dryNumber(dry, numbers) {
  return Array(numbers)
    .fill("uwu")
    .map((el, idx) => idx + 1)
    .filter(el => `${el}`.includes(dry))
}
