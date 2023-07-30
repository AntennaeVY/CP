function wrapping(gifts: string[]): string[] {
  const wrapped: string[] = [];
  
  for (const gift of gifts) {
    wrapped.push(
      "*".repeat(gift.length+2) 
      + `\n*${gift}*\n` +
      "*".repeat(gift.length+2)
    )
  }

  return wrapped;
}
