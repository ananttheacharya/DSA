def largest_integer(nums, k)
  cnt = Array.new(51, 0)

  nums.each do |x|
    cnt[x] += 1
  end

  return nums.max if k == nums.length

  if k == 1
    ans = -1

    nums.each do |x|
      ans = [ans, x].max if cnt[x] == 1
    end

    return ans
  end

  a = cnt[nums[0]] == 1 ? nums[0] : -1
  b = cnt[nums[-1]] == 1 ? nums[-1] : -1

  [a, b].max
end