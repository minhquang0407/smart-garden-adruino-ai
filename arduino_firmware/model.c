#include <string.h>
#include "model.h"

#include <string.h>
void add_vectors(float *v1, float *v2, int size, float *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] + v2[i];
}
void mul_vector_number(float *v1, float num, int size, float *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] * num;
}
void score(float * input, float * output) {
    float var0[2];
    float var1[2];
    float var2[2];
    float var3[2];
    float var4[2];
    float var5[2];
    if (input[1] <= 431.0) {
        if (input[0] <= 3.5) {
            if (input[0] <= 1.5) {
                memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
            } else {
                if (input[3] <= 26.0) {
                    if (input[1] <= 275.0) {
                        memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                    } else {
                        memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                    }
                } else {
                    if (input[2] <= 25.5) {
                        memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                    } else {
                        if (input[3] <= 35.5) {
                            if (input[2] <= 28.0) {
                                memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            } else {
                                if (input[0] <= 2.5) {
                                    memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                } else {
                                    if (input[1] <= 239.5) {
                                        memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                    } else {
                                        memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                    }
                                }
                            }
                        } else {
                            if (input[1] <= 285.0) {
                                memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            } else {
                                memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            }
                        }
                    }
                }
            }
        } else {
            memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
        }
    } else {
        if (input[0] <= 5.5) {
            if (input[2] <= 22.5) {
                memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
            } else {
                if (input[0] <= 0.5) {
                    memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                } else {
                    if (input[0] <= 1.5) {
                        if (input[3] <= 18.5) {
                            if (input[1] <= 569.5) {
                                memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            } else {
                                memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            }
                        } else {
                            if (input[2] <= 25.0) {
                                if (input[3] <= 19.5) {
                                    memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                } else {
                                    memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                }
                            } else {
                                if (input[1] <= 559.0) {
                                    memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                } else {
                                    memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                }
                            }
                        }
                    } else {
                        if (input[1] <= 469.5) {
                            if (input[1] <= 445.0) {
                                memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            } else {
                                if (input[0] <= 4.5) {
                                    memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                } else {
                                    memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                }
                            }
                        } else {
                            memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        }
                    }
                }
            }
        } else {
            if (input[3] <= 20.0) {
                if (input[2] <= 20.0) {
                    memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                } else {
                    memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                }
            } else {
                if (input[1] <= 688.5) {
                    if (input[1] <= 600.5) {
                        memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                    } else {
                        if (input[1] <= 634.0) {
                            memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        } else {
                            memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        }
                    }
                } else {
                    if (input[3] <= 31.5) {
                        if (input[1] <= 737.5) {
                            memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        } else {
                            if (input[2] <= 33.5) {
                                memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            } else {
                                memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            }
                        }
                    } else {
                        if (input[2] <= 24.0) {
                            memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        } else {
                            if (input[1] <= 865.0) {
                                memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            } else {
                                if (input[3] <= 33.5) {
                                    memcpy(var5, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                } else {
                                    memcpy(var5, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    float var6[2];
    if (input[2] <= 29.5) {
        if (input[3] <= 25.5) {
            if (input[2] <= 23.5) {
                if (input[3] <= 14.5) {
                    memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                } else {
                    if (input[2] <= 22.5) {
                        if (input[0] <= 5.5) {
                            if (input[1] <= 424.0) {
                                memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            } else {
                                memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            }
                        } else {
                            if (input[3] <= 16.5) {
                                if (input[1] <= 475.0) {
                                    memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                } else {
                                    memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                }
                            } else {
                                memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            }
                        }
                    } else {
                        if (input[0] <= 3.5) {
                            memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        } else {
                            if (input[1] <= 730.0) {
                                memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            } else {
                                if (input[3] <= 19.0) {
                                    memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                } else {
                                    memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                }
                            }
                        }
                    }
                }
            } else {
                if (input[1] <= 488.0) {
                    if (input[2] <= 25.5) {
                        if (input[0] <= 1.5) {
                            if (input[0] <= 0.5) {
                                if (input[2] <= 24.5) {
                                    if (input[1] <= 393.0) {
                                        memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                    } else {
                                        memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                    }
                                } else {
                                    memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                }
                            } else {
                                memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            }
                        } else {
                            if (input[0] <= 4.5) {
                                if (input[1] <= 280.0) {
                                    memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                } else {
                                    memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                }
                            } else {
                                memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            }
                        }
                    } else {
                        if (input[1] <= 387.5) {
                            memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        } else {
                            if (input[0] <= 0.5) {
                                memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            } else {
                                if (input[2] <= 27.5) {
                                    memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                } else {
                                    memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                }
                            }
                        }
                    }
                } else {
                    memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                }
            }
        } else {
            if (input[1] <= 431.0) {
                if (input[0] <= 3.5) {
                    if (input[2] <= 28.0) {
                        memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                    } else {
                        if (input[1] <= 282.5) {
                            memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        } else {
                            memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        }
                    }
                } else {
                    memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                }
            } else {
                if (input[0] <= 5.5) {
                    if (input[3] <= 37.5) {
                        if (input[2] <= 25.0) {
                            memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        } else {
                            memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        }
                    } else {
                        memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                    }
                } else {
                    if (input[1] <= 487.5) {
                        memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                    } else {
                        if (input[3] <= 33.0) {
                            memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        } else {
                            memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        }
                    }
                }
            }
        }
    } else {
        if (input[0] <= 4.5) {
            if (input[3] <= 15.5) {
                if (input[1] <= 286.0) {
                    memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                } else {
                    memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                }
            } else {
                memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
            }
        } else {
            if (input[2] <= 36.0) {
                if (input[1] <= 677.5) {
                    if (input[1] <= 529.5) {
                        memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                    } else {
                        if (input[1] <= 635.5) {
                            memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        } else {
                            memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        }
                    }
                } else {
                    if (input[1] <= 742.5) {
                        memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                    } else {
                        if (input[2] <= 33.5) {
                            memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        } else {
                            memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        }
                    }
                }
            } else {
                if (input[3] <= 26.0) {
                    memcpy(var6, (float[]){1.0, 0.0}, 2 * sizeof(float));
                } else {
                    memcpy(var6, (float[]){0.0, 1.0}, 2 * sizeof(float));
                }
            }
        }
    }
    add_vectors(var5, var6, 2, var4);
    float var7[2];
    if (input[2] <= 29.5) {
        if (input[1] <= 431.0) {
            if (input[1] <= 399.0) {
                if (input[2] <= 28.5) {
                    memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                } else {
                    if (input[0] <= 2.5) {
                        if (input[3] <= 27.0) {
                            if (input[1] <= 282.0) {
                                memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            } else {
                                memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            }
                        } else {
                            memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        }
                    } else {
                        if (input[3] <= 30.5) {
                            memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        } else {
                            if (input[1] <= 275.5) {
                                memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            } else {
                                memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            }
                        }
                    }
                }
            } else {
                if (input[3] <= 23.0) {
                    if (input[0] <= 4.5) {
                        if (input[0] <= 2.0) {
                            memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        } else {
                            memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        }
                    } else {
                        memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                    }
                } else {
                    memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                }
            }
        } else {
            if (input[2] <= 22.5) {
                if (input[1] <= 694.5) {
                    if (input[0] <= 5.5) {
                        memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                    } else {
                        if (input[3] <= 27.5) {
                            memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        } else {
                            memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        }
                    }
                } else {
                    if (input[3] <= 13.5) {
                        memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                    } else {
                        if (input[2] <= 21.5) {
                            if (input[3] <= 26.0) {
                                memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            } else {
                                memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            }
                        } else {
                            memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        }
                    }
                }
            } else {
                if (input[1] <= 494.5) {
                    if (input[0] <= 0.5) {
                        memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                    } else {
                        if (input[1] <= 445.0) {
                            memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        } else {
                            if (input[1] <= 453.0) {
                                if (input[3] <= 34.5) {
                                    if (input[3] <= 19.0) {
                                        memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                    } else {
                                        if (input[2] <= 26.5) {
                                            memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                        } else {
                                            memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                        }
                                    }
                                } else {
                                    memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                }
                            } else {
                                memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            }
                        }
                    }
                } else {
                    if (input[2] <= 23.5) {
                        if (input[0] <= 3.5) {
                            memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        } else {
                            if (input[1] <= 730.0) {
                                memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            } else {
                                if (input[1] <= 890.0) {
                                    memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                } else {
                                    memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                }
                            }
                        }
                    } else {
                        if (input[0] <= 5.5) {
                            memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        } else {
                            if (input[3] <= 33.0) {
                                memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            } else {
                                memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (input[3] <= 34.5) {
            if (input[0] <= 4.5) {
                if (input[1] <= 265.0) {
                    memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                } else {
                    memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                }
            } else {
                if (input[1] <= 550.0) {
                    memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                } else {
                    if (input[1] <= 782.5) {
                        memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                    } else {
                        memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                    }
                }
            }
        } else {
            if (input[3] <= 40.5) {
                if (input[2] <= 31.0) {
                    memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
                } else {
                    memcpy(var7, (float[]){0.0, 1.0}, 2 * sizeof(float));
                }
            } else {
                memcpy(var7, (float[]){1.0, 0.0}, 2 * sizeof(float));
            }
        }
    }
    add_vectors(var4, var7, 2, var3);
    float var8[2];
    if (input[1] <= 412.5) {
        if (input[1] <= 349.5) {
            if (input[1] <= 329.5) {
                memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
            } else {
                if (input[2] <= 26.5) {
                    memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
                } else {
                    if (input[0] <= 4.5) {
                        memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                    } else {
                        memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
                    }
                }
            }
        } else {
            if (input[0] <= 3.5) {
                if (input[2] <= 23.5) {
                    memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
                } else {
                    if (input[0] <= 1.0) {
                        memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
                    } else {
                        memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                    }
                }
            } else {
                memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
            }
        }
    } else {
        if (input[3] <= 16.5) {
            if (input[2] <= 23.5) {
                if (input[1] <= 609.0) {
                    if (input[0] <= 3.0) {
                        memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                    } else {
                        memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
                    }
                } else {
                    if (input[2] <= 22.5) {
                        memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                    } else {
                        if (input[3] <= 15.5) {
                            memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        } else {
                            memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        }
                    }
                }
            } else {
                memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
            }
        } else {
            if (input[0] <= 5.5) {
                if (input[1] <= 493.5) {
                    if (input[3] <= 18.5) {
                        if (input[0] <= 0.5) {
                            memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        } else {
                            memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        }
                    } else {
                        if (input[2] <= 29.5) {
                            if (input[3] <= 55.0) {
                                if (input[3] <= 22.5) {
                                    if (input[3] <= 20.5) {
                                        if (input[3] <= 19.5) {
                                            memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                        } else {
                                            memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                        }
                                    } else {
                                        memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                    }
                                } else {
                                    memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                }
                            } else {
                                memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            }
                        } else {
                            memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        }
                    }
                } else {
                    memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                }
            } else {
                if (input[1] <= 683.5) {
                    if (input[2] <= 37.5) {
                        if (input[2] <= 22.5) {
                            if (input[1] <= 516.0) {
                                memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            } else {
                                memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            }
                        } else {
                            memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        }
                    } else {
                        if (input[1] <= 550.0) {
                            memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        } else {
                            memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        }
                    }
                } else {
                    if (input[1] <= 780.0) {
                        if (input[2] <= 24.0) {
                            if (input[2] <= 22.5) {
                                memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            } else {
                                memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            }
                        } else {
                            memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        }
                    } else {
                        if (input[3] <= 33.0) {
                            if (input[2] <= 33.5) {
                                if (input[3] <= 31.5) {
                                    memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                } else {
                                    if (input[2] <= 29.0) {
                                        memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                    } else {
                                        memcpy(var8, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                    }
                                }
                            } else {
                                memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            }
                        } else {
                            memcpy(var8, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        }
                    }
                }
            }
        }
    }
    add_vectors(var3, var8, 2, var2);
    float var9[2];
    if (input[1] <= 399.0) {
        if (input[1] <= 294.5) {
            memcpy(var9, (float[]){1.0, 0.0}, 2 * sizeof(float));
        } else {
            if (input[2] <= 24.5) {
                memcpy(var9, (float[]){1.0, 0.0}, 2 * sizeof(float));
            } else {
                if (input[2] <= 29.5) {
                    if (input[0] <= 3.5) {
                        if (input[0] <= 1.0) {
                            memcpy(var9, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        } else {
                            memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        }
                    } else {
                        memcpy(var9, (float[]){1.0, 0.0}, 2 * sizeof(float));
                    }
                } else {
                    if (input[3] <= 31.0) {
                        memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                    } else {
                        memcpy(var9, (float[]){1.0, 0.0}, 2 * sizeof(float));
                    }
                }
            }
        }
    } else {
        if (input[0] <= 4.5) {
            if (input[1] <= 492.0) {
                if (input[2] <= 29.5) {
                    if (input[1] <= 457.5) {
                        if (input[0] <= 0.5) {
                            memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        } else {
                            if (input[2] <= 28.0) {
                                memcpy(var9, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            } else {
                                memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            }
                        }
                    } else {
                        if (input[2] <= 26.5) {
                            if (input[0] <= 0.5) {
                                memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            } else {
                                memcpy(var9, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            }
                        } else {
                            memcpy(var9, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        }
                    }
                } else {
                    memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                }
            } else {
                memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
            }
        } else {
            if (input[2] <= 22.5) {
                if (input[0] <= 5.5) {
                    memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                } else {
                    if (input[1] <= 715.0) {
                        if (input[2] <= 20.0) {
                            memcpy(var9, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        } else {
                            if (input[3] <= 14.5) {
                                memcpy(var9, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            } else {
                                memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            }
                        }
                    } else {
                        memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                    }
                }
            } else {
                if (input[1] <= 575.0) {
                    memcpy(var9, (float[]){1.0, 0.0}, 2 * sizeof(float));
                } else {
                    if (input[2] <= 23.5) {
                        if (input[1] <= 730.0) {
                            memcpy(var9, (float[]){1.0, 0.0}, 2 * sizeof(float));
                        } else {
                            if (input[3] <= 19.0) {
                                memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                            } else {
                                memcpy(var9, (float[]){1.0, 0.0}, 2 * sizeof(float));
                            }
                        }
                    } else {
                        if (input[0] <= 5.5) {
                            memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                        } else {
                            if (input[1] <= 767.5) {
                                if (input[2] <= 36.0) {
                                    if (input[1] <= 698.5) {
                                        if (input[3] <= 40.0) {
                                            memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                        } else {
                                            memcpy(var9, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                        }
                                    } else {
                                        memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                    }
                                } else {
                                    memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                }
                            } else {
                                if (input[2] <= 28.5) {
                                    memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                } else {
                                    if (input[1] <= 935.0) {
                                        if (input[2] <= 33.5) {
                                            memcpy(var9, (float[]){1.0, 0.0}, 2 * sizeof(float));
                                        } else {
                                            memcpy(var9, (float[]){0.6666666666666666, 0.3333333333333333}, 2 * sizeof(float));
                                        }
                                    } else {
                                        memcpy(var9, (float[]){0.0, 1.0}, 2 * sizeof(float));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    add_vectors(var2, var9, 2, var1);
    mul_vector_number(var1, 0.2, 2, var0);
    memcpy(output, var0, 2 * sizeof(float));
}

