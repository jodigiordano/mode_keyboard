# Generates an LED gamma-correction table for each RGB component of the LED.

max_input = 256

[['R', 128, 5.8], ['G', 256, 0.5], ['B', 512, 0.3]].each do |(component, max_steps, gamma)|
  puts "const uint16_t gammaCorrection#{component}[#{max_input}] = {"

  puts (0...max_input)
    .map{ |step| [((step / max_input.to_f) ** gamma) * max_steps + 0.5, max_steps - 1].min }
    .map{ |point| point.to_i.to_s.rjust(max_steps.to_s.chars.count) }
    .each_slice(16)
    .map{ |points| points.join(', ') }
    .map{ |line| "  #{line}, " }
    .join("\n")

  puts '};'
  puts
end
