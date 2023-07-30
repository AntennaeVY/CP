import kotlin.math.max;

fun growingPlant(upSpeed: Int, downSpeed: Int, desiredHeight: Int): Int {
  val delta = upSpeed - downSpeed;
    
  return max(1, (desiredHeight - upSpeed + delta - 1)/delta + 1);
}